#ifdef _WIN32

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>

int WINAPI
wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd){

    

    return 0;
}

#endif /* _WIN32 */

#ifdef __linux__

#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char *argv[]){

    
    
    return 0;
}

#endif /* __linux__ */