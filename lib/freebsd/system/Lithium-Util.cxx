#include "../../.././include/system/Lithium-System-FreeBSD.hh"

#include <sys/ptrace.h>

#ifdef __FreeBSD__

bool Lithium_System::Util::Debugger()
{
    return ptrace(0, 0,0, 0);
}

unsigned int Lithium_System::Util::WindowHeight(Window window)
{
    if (!window) return 1;

    return WindowHeight(window);
}

unsigned int Lithium_System::Util::WindowWidth(Window window)
{
    if (!window) return 1;

    return WindowWidth(window);
}

unsigned int Lithium_System::Util::ScreenHeight()
{
    Display *dsp = XOpenDisplay(NULL);
    if (!dsp) return 1;

    unsigned int res = DisplayHeight(dsp, 0);
    XCloseDisplay(dsp);

    return res;
}

unsigned int Lithium_System::Util::ScreenWidth()
{
    Display *dsp = XOpenDisplay(NULL);
    if (!dsp) return 1;

    unsigned int res = XDisplayWidth(dsp, 0);
    XCloseDisplay(dsp);

    return res;
}

#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments