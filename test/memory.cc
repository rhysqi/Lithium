#include <stdio.h>
#include <fcntl.h>

int LiTestSSE42()
{
    unsigned int x = 0;

    __asm__ volatile(
        "crc32 %1, %0"
        : "+r"(x)
        : "r"(0)
    );

    return 1;
}

int main(int argc, const char *argv[]){
    
    // open("file.txt", O_CREAT, 0777);
    // openat(int, const char *, int, ...)

    LiTestSSE42();

    return 0;
}