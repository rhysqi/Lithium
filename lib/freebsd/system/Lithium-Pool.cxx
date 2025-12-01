#include "../../.././include/system/Lithium-System-FreeBSD.hh"

#ifdef __FreeBSD__

#include <sys/mman.h>

#include <X11/Xlib.h>

using namespace Lithium_System::Types;

void *Lithium_System::Pool::Memory::Virtual::Create(uint uPoolCount, pVirtual_Pool_t Virtual_Pool_t)
{
    pvoid pMemoryPool;
    pMemoryPool = { };

    
    return pMemoryPool;
}

int Lithium_System::Pool::Memory::Virtual::Destroy(void *pMemoryPool)
{
    void *PoolFree = *pMemoryPool[1];
    // munmap(pMemoryPool, sizeof(pMemoryPool));

    return 0;
}

int Lithium_System::Pool::Memory::Virtual::Lock(void *pMemoryPool)
{
    if (!pMemoryPool) return 1;

    return mlock(pMemoryPool, sizeof(pMemoryPool));
}

#endif /* __FreeBSD__ */