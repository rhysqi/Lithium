#include "../../../include/system/Lithium-System-FreeBSD.hh"

#include <sys/event.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <security/pam_appl.h>

#include <unistd.h>

typedef struct {
    size_t size;
    off_t offset_t;
    int iFlags;
    int iProt;
} File_desc_t, *pFile_Desc_t;

pFile_Desc_t g_FD_t = (pFile_Desc_t)0;

void Directory_Event_Notifier(int dd)
{
    
}

int Lithium_System::Directory::Create(const char *dirname)
{
    int md = mkdir(dirname, 0777);
    int kq = kqueue();

    if (!kq) return -1;

    if (md) {
        
    }

    return -1;
}

int Lithium_System::Directory::Remove(const char *dirname)
{
    int md = rmdir(dirname);

    
    return md;
}

Lithium_System::File::Desc Lithium_System::File::Create(const char *filename, int permission)
{
    Desc d;
    int fd = open("./", O_DIRECTORY);

    if (!fd) return d;

    if (!openat(fd, filename, O_CREAT, permission)) return d;

    close(fd);

    return d;
}

unsigned long long Lithium_System::File::Size(const char *filepath)
{
    struct stat st;

    if (stat(filepath, &st) == 0) return st.st_size;

    return false;
}