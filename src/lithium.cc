#include <X11/Xlib.h>
#include <stdio.h>

int main() {
    // Menginisialisasi koneksi ke X server
    Display *display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Tidak dapat terhubung ke X server.\n");
        return 1;
    }

    // Mendefinisikan beberapa atribut untuk window
    int screen_num = DefaultScreen(display);
    unsigned int border_width = 2;
    unsigned int window_width = 400;
    unsigned int window_height = 300;
    unsigned int border_color = BlackPixel(display, screen_num);
    unsigned int background_color = WhitePixel(display, screen_num);

    // Membuat window sederhana
    Window root = DefaultRootWindow(display);
    Window window = XCreateSimpleWindow(display, root, 10, 10, window_width, window_height,
                                       border_width, border_color, background_color);

    // Mengatur judul window
    XStoreName(display, window, "Window Sederhana");

    // Menampilkan window
    XMapWindow(display, window);

    // Menunggu untuk event
    XEvent event;
    while (1) {
        XNextEvent(display, &event);
    }

    // Menutup koneksi ke X server (biasanya tidak akan tercapai karena loop di atas)
    XCloseDisplay(display);

    return 0;
}
