#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdbool.h>

void handle_event(XEvent* event) {
    switch(event->type) {
        case KeyPress:
            // Contoh: tekan Escape untuk keluar
            if(XLookupKeysym(&event->xkey, 0) == XK_Escape) {
                // nanti loop akan berhenti
            }
            break;
        case ClientMessage:
            // Handle window close
            break;
        default:
            break;
    }
}

int main() {
    Display* display = XOpenDisplay(NULL);
    if (!display) return 1;

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);

    Window win = XCreateSimpleWindow(display, root, 100, 100, 640, 480, 1,
                                     BlackPixel(display, screen),
                                     WhitePixel(display, screen));
    XSelectInput(display, win, ExposureMask | KeyPressMask | StructureNotifyMask);
    XMapWindow(display, win);

    bool exit_loop = false;

    // --- Loop host berdasarkan XPending ---
    while (XPending(display) > 0 || !exit_loop) {
        while (XPending(display) > 0) {
            XEvent event;
            XNextEvent(display, &event);
            handle_event(&event);

            // exit flag
            if (event.type == KeyPress &&
                XLookupKeysym(&event.xkey, 0) == XK_Escape) {
                exit_loop = true;
            }
            if (event.type == ClientMessage) {
                exit_loop = true;
            }
        }
    }

    XDestroyWindow(display, win);
    XCloseDisplay(display);

    return 0;
}
