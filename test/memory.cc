#include <fcntl.h>

int main(int argc, const char *argv[]){
    
    open("file.txt", O_CREAT, 0777);
    openat(int, const char *, int, ...)

    return 0;
}