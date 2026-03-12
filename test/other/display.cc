/**
 * Lithium - X11 Borderless Window + Async Drag + RGB Cycling
 * FreeBSD / Xlib Implementation
 *
 * Window tanpa non-client area (no title bar, no decorations).
 * Spawn tepat di tengah display. Background cycling RGB secara async.
 *
 * Mekanisme drag:
 *   - ButtonPress  : mulai drag, grab pointer dengan GrabModeAsync
 *   - MotionNotify : hitung delta, pindahkan window via XMoveWindow
 *   - ButtonRelease: lepas grab, drag selesai
 *
 * Mekanisme RGB cycling:
 *   - Event loop pakai select() dengan timeout 16ms (~60fps)
 *   - Jika tidak ada X event, rgb_tick() dipanggil untuk update warna
 *   - XSetWindowBackground + XClearWindow untuk apply warna baru
 *   - Tidak ada thread, tidak ada blocking — murni single-threaded async
 *
 * Spawn position:
 *   - DisplayWidth / DisplayHeight dipakai untuk hitung center display
 *   - Window spawn tepat di tengah saat pertama kali muncul
 *
 * Compile:
 *   clang++ -o lithium-window Lithium-Window-X11.cxx -lX11
 *
 * Run:
 *   ./lithium-window
 */

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#include <sys/select.h>  /* select(), fd_set — FreeBSD syscall native  */
#include <sys/time.h>    /* struct timeval                              */

/* -----------------------------------------------------------------------
 * Motif Hints — matikan WM decorations secara proper.
 * --------------------------------------------------------------------- */
#define MWM_HINTS_DECORATIONS   (1L << 1)
#define MWM_DECOR_NONE          0

typedef struct {
    unsigned long flags;
    unsigned long functions;
    unsigned long decorations;
    long          input_mode;
    unsigned long status;
} MotifWmHints;

/* -----------------------------------------------------------------------
 * Konstanta Window
 * --------------------------------------------------------------------- */
static const int WINDOW_WIDTH  = 900;
static const int WINDOW_HEIGHT = 600;
static const int BORDER_WIDTH  = 0;

/* -----------------------------------------------------------------------
 * RgbState — state untuk HSV-based RGB color cycling.
 *
 * Kita cycle hue 0–360 derajat secara kontinu.
 * HSV → RGB dilakukan manual tanpa library tambahan.
 * Hasilnya smooth rainbow cycling yang vivid dan tidak pucat.
 * --------------------------------------------------------------------- */
struct RgbState {
    float hue;    /* current hue: 0.0 – 360.0 derajat */
    float speed;  /* derajat per tick (~16ms per tick) */
};

/* -----------------------------------------------------------------------
 * Fungsi: hsv_to_pixel
 *
 * Konversi HSV → packed 32-bit RGB pixel (0x00RRGGBB).
 * Saturation = 1.0, Value = 1.0 → warna selalu maksimal vivid.
 * --------------------------------------------------------------------- */
static unsigned long
hsv_to_pixel(float h)
{
    float c = 1.0f;
    float x = c * (1.0f - __builtin_fabsf(__builtin_fmodf(h / 60.0f, 2.0f) - 1.0f));

    float r, g, b;

    if      (h < 60.0f)  { r = c; g = x; b = 0; }
    else if (h < 120.0f) { r = x; g = c; b = 0; }
    else if (h < 180.0f) { r = 0; g = c; b = x; }
    else if (h < 240.0f) { r = 0; g = x; b = c; }
    else if (h < 300.0f) { r = x; g = 0; b = c; }
    else                  { r = c; g = 0; b = x; }

    unsigned long R = (unsigned long)(r * 255.0f);
    unsigned long G = (unsigned long)(g * 255.0f);
    unsigned long B = (unsigned long)(b * 255.0f);

    return (R << 16) | (G << 8) | B;
}

/* -----------------------------------------------------------------------
 * Fungsi: rgb_tick
 *
 * Dipanggil tiap frame (~16ms) dari event loop via select() timeout.
 * Advance hue → hitung pixel baru → apply ke window background.
 *
 * XSetWindowBackground  → update pixel background di X server
 * XClearWindow          → instruksikan server redraw dengan warna baru
 * XFlush                → kirim request ke server (non-blocking)
 *
 * Tidak ada XSync — XFlush saja cukup supaya tidak blocking.
 * --------------------------------------------------------------------- */
static void
rgb_tick(Display *dpy, Window win, RgbState *rgb)
{
    rgb->hue += rgb->speed;
    if (rgb->hue >= 360.0f)
        rgb->hue -= 360.0f;

    unsigned long pixel = hsv_to_pixel(rgb->hue);

    XSetWindowBackground(dpy, win, pixel);
    XClearWindow(dpy, win);
    XFlush(dpy);
}

/* -----------------------------------------------------------------------
 * DragState — state machine untuk async window drag.
 * --------------------------------------------------------------------- */
struct DragState {
    int active;
    int start_ptr_x;
    int start_ptr_y;
    int start_win_x;
    int start_win_y;
};

/* -----------------------------------------------------------------------
 * Fungsi: drag_begin
 *
 * Grab pointer dengan GrabModeAsync — server tidak blocking,
 * event delivery tetap jalan normal selama drag berlangsung.
 * --------------------------------------------------------------------- */
static void
drag_begin(Display *dpy, Window win, DragState *drag,
           int ptr_x_root, int ptr_y_root)
{
    Window child;
    int    dummy_x, dummy_y;
    unsigned int w, h, bw, depth;
    XGetGeometry(dpy, win, &child, &dummy_x, &dummy_y, &w, &h, &bw, &depth);

    int rx, ry;
    XTranslateCoordinates(dpy, win, DefaultRootWindow(dpy),
                          0, 0, &rx, &ry, &child);

    drag->start_ptr_x = ptr_x_root;
    drag->start_ptr_y = ptr_y_root;
    drag->start_win_x = rx;
    drag->start_win_y = ry;

    int result = XGrabPointer(
        dpy,
        win,
        True,
        ButtonReleaseMask | PointerMotionMask,
        GrabModeAsync,   /* pointer_mode  — tidak blocking */
        GrabModeAsync,   /* keyboard_mode — tidak blocking */
        None,
        None,
        CurrentTime
    );

    if (result == GrabSuccess)
        drag->active = 1;
}

/* -----------------------------------------------------------------------
 * Fungsi: drag_update
 *
 * Hitung delta posisi, pindahkan window. XMoveWindow langsung return.
 * XFlush supaya request segera dikirim tanpa nunggu event berikutnya.
 * --------------------------------------------------------------------- */
static void
drag_update(Display *dpy, Window win, DragState *drag,
            int ptr_x_root, int ptr_y_root)
{
    if (!drag->active) return;

    int new_x = drag->start_win_x + (ptr_x_root - drag->start_ptr_x);
    int new_y = drag->start_win_y + (ptr_y_root - drag->start_ptr_y);

    XMoveWindow(dpy, win, new_x, new_y);
    XFlush(dpy);
}

/* -----------------------------------------------------------------------
 * Fungsi: drag_end — lepas pointer grab, kembali ke routing normal.
 * --------------------------------------------------------------------- */
static void
drag_end(Display *dpy, DragState *drag)
{
    if (!drag->active) return;
    XUngrabPointer(dpy, CurrentTime);
    drag->active = 0;
}

/* -----------------------------------------------------------------------
 * Fungsi: strip_decorations
 *
 * Matikan semua dekorasi WM via _MOTIF_WM_HINTS.
 * Kompatibel dengan semua WM modern di FreeBSD (XFWM, Openbox, dst).
 * --------------------------------------------------------------------- */
static void
strip_decorations(Display *dpy, Window win)
{
    Atom atom = XInternAtom(dpy, "_MOTIF_WM_HINTS", False);

    MotifWmHints hints  = {};
    hints.flags         = MWM_HINTS_DECORATIONS;
    hints.decorations   = MWM_DECOR_NONE;

    XChangeProperty(dpy, win, atom, atom, 32, PropModeReplace,
                    (unsigned char *)&hints,
                    sizeof(MotifWmHints) / sizeof(long));
}

/* -----------------------------------------------------------------------
 * Fungsi: set_window_type
 *
 * Set _NET_WM_WINDOW_TYPE_NORMAL supaya WM tetap manage window ini
 * (focus, minimize, taskbar) tapi tanpa render dekorasi.
 * --------------------------------------------------------------------- */
static void
set_window_type(Display *dpy, Window win)
{
    Atom type   = XInternAtom(dpy, "_NET_WM_WINDOW_TYPE", False);
    Atom normal = XInternAtom(dpy, "_NET_WM_WINDOW_TYPE_NORMAL", False);

    XChangeProperty(dpy, win, type, XA_ATOM, 32, PropModeReplace,
                    (unsigned char *)&normal, 1);
}

/* -----------------------------------------------------------------------
 * Fungsi: set_wm_delete_protocol
 *
 * Daftarkan WM_DELETE_WINDOW supaya close dari taskbar bisa di-handle
 * secara graceful, tidak di-kill paksa oleh WM.
 * --------------------------------------------------------------------- */
static Atom
set_wm_delete_protocol(Display *dpy, Window win)
{
    Atom wm_delete = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(dpy, win, &wm_delete, 1);
    return wm_delete;
}

/* -----------------------------------------------------------------------
 * Entry Point
 * --------------------------------------------------------------------- */
int
main(void)
{
    /* 1. Buka koneksi ke X server */
    Display *dpy = XOpenDisplay(nullptr);
    if (!dpy) return 1;

    int    screen = DefaultScreen(dpy);
    Window root   = RootWindow(dpy, screen);

    /* 2. Hitung posisi spawn tepat di tengah display
     *
     *    DisplayWidth / DisplayHeight mengembalikan resolusi display
     *    aktual dalam pixel langsung dari X server.
     *
     *    Formula center:
     *      spawn_x = (display_w - window_w) / 2
     *      spawn_y = (display_h - window_h) / 2
     */
    int display_w = DisplayWidth(dpy, screen);
    int display_h = DisplayHeight(dpy, screen);

    int spawn_x = (display_w - WINDOW_WIDTH)  / 2;
    int spawn_y = (display_h - WINDOW_HEIGHT) / 2;

    /* 3. Setup XSetWindowAttributes */
    XSetWindowAttributes attrs = {};
    attrs.background_pixel = 0xFF0000;  /* merah awal — langsung diganti rgb_tick */
    attrs.event_mask       = ExposureMask
                           | KeyPressMask
                           | ButtonPressMask
                           | ButtonReleaseMask
                           | PointerMotionMask
                           | StructureNotifyMask;
    attrs.colormap         = DefaultColormap(dpy, screen);

    unsigned long attr_mask = CWBackPixel | CWEventMask | CWColormap;

    /* 4. XCreateWindow — bukan XCreateSimpleWindow */
    Window win = XCreateWindow(
        dpy,
        root,
        spawn_x,                    /* x: center horizontal */
        spawn_y,                    /* y: center vertical   */
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        BORDER_WIDTH,
        DefaultDepth(dpy, screen),
        InputOutput,
        DefaultVisual(dpy, screen),
        attr_mask,
        &attrs
    );

    /* 5. Strip semua dekorasi WM */
    strip_decorations(dpy, win);

    /* 6. Set window type */
    set_window_type(dpy, win);

    /* 7. Set nama window */
    XStoreName(dpy, win, "Lithium");

    /* 8. Daftarkan WM_DELETE_WINDOW */
    Atom wm_delete = set_wm_delete_protocol(dpy, win);

    /* 9. Map window */
    XMapWindow(dpy, win);
    XFlush(dpy);

    /* ---------------------------------------------------------------
     * State inisialisasi
     * ------------------------------------------------------------- */
    DragState drag = {};
    drag.active    = 0;

    RgbState rgb   = {};
    rgb.hue        = 0.0f;
    rgb.speed      = 1.2f;  /* ~1.2 derajat/frame → full rainbow cycle ~5 detik */

    /*
     * File descriptor X connection.
     * select() pakai fd ini untuk tahu kapan X event masuk
     * tanpa busy-wait yang memakan CPU.
     */
    int x_fd = ConnectionNumber(dpy);

    /* ---------------------------------------------------------------
     * Event Loop — select()-based async loop
     *
     * Arsitektur:
     *   1. select() tunggu X event ATAU timeout 16ms habis
     *   2. Jika ada X event  → proses semua pending event
     *   3. Jika timeout      → panggil rgb_tick() untuk update warna
     *
     * Hasilnya:
     *   - UI tidak pernah blocking, select() return segera ada event
     *   - RGB cycling tetap smooth ~60fps walau user idle
     *   - Drag dan RGB berjalan bersamaan tanpa saling block
     * ------------------------------------------------------------- */
    XEvent ev;
    int    running = 1;

    while (running) {

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(x_fd, &fds);

        /* 16ms timeout = ~60fps frame rate untuk rgb_tick */
        struct timeval timeout;
        timeout.tv_sec  = 0;
        timeout.tv_usec = 16000;

        int ready = select(x_fd + 1, &fds, nullptr, nullptr, &timeout);

        if (ready < 0) {
            /* select() di-interrupt signal — lanjut loop */
            continue;
        }

        if (ready == 0) {
            /* Timeout: tidak ada X event → ini frame tick kita */
            rgb_tick(dpy, win, &rgb);
            continue;
        }

        /* Ada X event — proses semua yang pending */
        while (XPending(dpy)) {
            XNextEvent(dpy, &ev);

            switch (ev.type) {

            case Expose:
                XFlush(dpy);
                break;

            case KeyPress: {
                KeySym key = XLookupKeysym(&ev.xkey, 0);
                if (key == XK_Escape)
                    running = 0;
                break;
            }

            case ButtonPress:
                if (ev.xbutton.button == Button1) {
                    drag_begin(dpy, win, &drag,
                               ev.xbutton.x_root,
                               ev.xbutton.y_root);
                }
                break;

            case MotionNotify: {
                /*
                 * Ambil MotionNotify paling baru saja — skip yang lama.
                 * Mencegah lag saat mouse bergerak lebih cepat dari 60fps.
                 */
                XEvent latest = ev;
                while (XCheckTypedWindowEvent(dpy, win, MotionNotify, &latest));

                if (drag.active) {
                    drag_update(dpy, win, &drag,
                                latest.xmotion.x_root,
                                latest.xmotion.y_root);
                }
                break;
            }

            case ButtonRelease:
                if (ev.xbutton.button == Button1)
                    drag_end(dpy, &drag);
                break;

            case ClientMessage:
                if ((Atom)ev.xclient.data.l[0] == wm_delete)
                    running = 0;
                break;

            case ConfigureNotify:
                /* Update OpenGL viewport di sini jika diperlukan */
                break;

            default:
                break;
            }
        }
    }

    /* Cleanup */
    XDestroyWindow(dpy, win);
    XCloseDisplay(dpy);

    return 0;
}