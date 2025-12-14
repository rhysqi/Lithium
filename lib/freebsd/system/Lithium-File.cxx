#include "../../../include/system/Lithium-System-FreeBSD.hh"

#include <fcntl.h>

int Lithium_System::File::CreateFile(const char *filename, int permission)
{
    int fd = open("./", O_DIRECTORY);

    if (!fd) return 1;

    if (!openat(fd, filename, O_CREAT, permission)) return 1;

    return 0;
}