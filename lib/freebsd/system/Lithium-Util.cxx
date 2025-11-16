#include "../../.././include/system/Lithium-System.hh"

#ifdef __FreeBSD__

#include <sys/ptrace.h>
#include <sys/capsicum.h>
#include <X11/Xlib.h>

bool Lithium_System::Util::Debugger()
{
    
}

uint Lithium_System::Util::ScreenHeight()
{
    
    return 0;
}

uint Lithium_System::Util::ScreenWidth()
{
    XDisplayWidth(XOpenDisplay(NULL), 0);
    return 0;
}

#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments