#include <Windows.h>
#include <fileapi.h>
#include <winnt.h>

int main(int argc, const char *argv[]){
    
    CreateFileA(
        argv[1], GENERIC_WRITE,
        FILE_SHARE_WRITE, NULL,
        CREATE_NEW, FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
    return 0;
}