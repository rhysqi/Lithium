#include "../../.././include/system/Lithium-System-FreeBSD.hh"

#include <sys/ptrace.h>

#ifdef __FreeBSD__

bool Lithium_System::Util::Debugger()
{
    return ptrace(0, 0,0, 0);
}

bool Lithium_System::Util::SSE42_Support()
{
    #if defined (__x86_64__) || defined (__i386__)

    return __builtin_cpu_supports("sse4.2");

    #else
        return false;
    
    #endif /* defined (__x86_64__) || defined (__i386__) */
}

bool Lithium_System::Util::AVX2_Support()
{
    #if defined (__x86_64__) || defined (__i386__)

    return __builtin_cpu_supports("avx2");

    #else
        return false;
    
    #endif /* defined (__x86_64__) || defined (__i386__) */
}

#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments