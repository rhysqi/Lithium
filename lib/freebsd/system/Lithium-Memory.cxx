#include "../../../include/system/Lithium-System-FreeBSD.hh"

#ifdef __FreeBSD__

#include <sys/mman.h>
#include <sys/capsicum.h>

using namespace Lithium_System::Types;

typedef struct Virtual_Memory_t {
    void *addr;
    size_t len;
    int iProt;
    int iFlags;
    int fd;
    off_t offset;
} *pVirtual_Memory_t;

pVirtual_Memory_t g_VAD_t = (pVirtual_Memory_t )0;

pvoid Lithium_System::Memory::Virtual::Create(void *pMemory, size_t len, int iProt, int iFlags, int iFd, off_t offset)
{
    
    return pMemory;
}

#endif /* __FreeBSD__ */