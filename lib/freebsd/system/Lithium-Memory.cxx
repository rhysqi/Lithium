#include "../../../include/system/Lithium-System-FreeBSD.hh"
#include "../../../include/types/Lithium-Types-FreeBSD.hh"

#ifdef __FreeBSD__

#include <sys/mman.h>

using namespace Lithium_Types;

typedef struct {
    lpVoid_t addr;
    size_t len;
    int iProt;
    int iFlags;
    int fd;
    off_t offset;
} VM_t, *pVM_t;

typedef struct {
    lpVoid_t p_VAD_t;
    pVM_t pVAD_;
} VAD_Table_t, *pVAD_Table_t;

pVAD_Table_t g_LTH_VAD_t = (pVAD_Table_t)0;

lpVoid_t VAD_Insert()
{
    

    return 0;
}

lpVoid_t Lithium_System::Memory::Virtual::Create(void *pMemory, size_t len, int iProt, int iFlags, int iFd, off_t offset)
{
    

    return pMemory;
}

#endif /* __FreeBSD__ */