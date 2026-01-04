#include <sys/mman.h>
#include <sys/types.h>

typedef struct Virtual_Memory_t {
    void *addr;
    size_t len;
    int iProt;
    int iFlags;
    int fd;
    off_t offset;
} *pVirtual_Memory_t;

pVirtual_Memory_t *g_VAD_t = nullptr;

void VAD_Insert(pVirtual_Memory_t g_VAD_t, pVirtual_Memory_t l_VAD_t)
{
    if (!g_VAD_t->addr) g_VAD_t->addr = l_VAD_t->addr;
    if (!g_VAD_t->len) g_VAD_t->len = l_VAD_t->len;
    if (!g_VAD_t->iProt) g_VAD_t->iProt = l_VAD_t->iProt;
    if (!g_VAD_t->iFlags) g_VAD_t->iFlags = l_VAD_t->iFlags;
    if (!g_VAD_t->fd) g_VAD_t->fd = l_VAD_t->fd;
    if (!g_VAD_t->offset) g_VAD_t->offset = l_VAD_t->offset;
}

void VAD_Query(void *pMemory)
{
    
}

void *Virtual_Create(void *pMemory, size_t len, int iProt, int iFlags, int iFd, off_t offset)
{
    void *pMem = mmap(pMemory, len, iProt, iFlags, iFd, offset);
    if(!pMem) return (void *)1;

    return pMem;
}

int main(int argc, const char *argv[]){
    
    
    return 0;
}