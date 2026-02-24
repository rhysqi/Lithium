#include "../../../include/window/Lithium-Window-FreeBSD.hh"

#include <X11/Xlib.h>

using namespace Lithium_Types;

unsigned int Lithium_Window::Util::WindowHeight(pWindow_t window)
{
    if (!window) return 1;

    return WindowHeight(window);
}

unsigned int Lithium_Window::Util::WindowWidth(pWindow_t window)
{
    if (!window) return 1;

    return WindowWidth(window);
}

unsigned int Lithium_Window::Util::ScreenHeight()
{
    Display *dsp = XOpenDisplay(NULL);
    if (!dsp) return 1;

    unsigned int res = DisplayHeight(dsp, 0);
    XCloseDisplay(dsp);

    return res;
}

unsigned int Lithium_Window::Util::ScreenWidth()
{
    Display *dsp = XOpenDisplay(NULL);
    if (!dsp) return 1;

    unsigned int res = XDisplayWidth(dsp, 0);
    XCloseDisplay(dsp);

    return res;
}