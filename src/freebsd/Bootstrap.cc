#include "../../include/Lithium.hh"

#include <sys/syscall.h>
#include <unistd.h>

void check_ASLR();
void check_AntiDebugger();
void Splashscreen();

void Bootstrap()
{
    #ifndef _DEBUG
    check_ASLR();
    check_AntiDebugger();
    #endif /* _DEBUG */
}

[[noreturn]]
static void terminate(int code)
{
    syscall(SYS_exit, code);
    __builtin_unreachable();
}

void check_ASLR()
{
    if (!Lithium_System::Util::ASLR())
        terminate(Lithium_Types::Error::Bootstrap_ASLR_Required);
}

void check_AntiDebugger()
{
    if (Lithium_System::Util::Debugger())
        terminate(Lithium_Types::Bootstrap_Debugger_Detected);
}