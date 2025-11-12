#include "../../.././include/Lithium-System.hh"

#pragma region FreeBSD System API Segments
#ifdef __FreeBSD__

#include <sys/ptrace.h>
#include <sys/capsicum.h>
// #include <X11/Xlib.h>

bool Lithium_System::Util::Debugger()
{
    
}

#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments