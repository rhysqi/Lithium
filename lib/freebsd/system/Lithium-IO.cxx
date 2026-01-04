#include "../../../include/system/Lithium-System-FreeBSD.hh"

#include <sys/event.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>

typedef struct File_desc_t {
    size_t size;
    off_t offset_t;
    int iFlags;
    int iProt;
} *pFile_Desc_t;

pFile_Desc_t g_FD_t = (pFile_Desc_t)0;

void Directory_Event_Notifier(int md)
{
    
}

int Lithium_System::Directory::Create(const char *dirname)
{
    int md = mkdir(dirname, 0777);

    if (!md) {
        // kevent
    }

    return md;
}

int Lithium_System::File::Create(const char *filename, int permission)
{
    int fd = open("./", O_DIRECTORY);

    if (!fd) return 1;

    if (!openat(fd, filename, O_CREAT, permission)) return 1;

    return 0;
}
