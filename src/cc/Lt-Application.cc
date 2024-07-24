#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <winbase.h>
#include <winnt.h>

_M128A __fastcall Lt_Noble_Entry(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    WNDCLASS wc = { };

    wc.lpfnWndProc   = NULL;
    wc.hInstance     = hInstance;
    wc.lpszClassName = NULL;

    RegisterClass(&wc);
}

long long __stdcall Lt_Noble_Main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    
    return 0;
}

void __stdcall Lt_Noble_App(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    WNDCLASS wc = { };

    wc.lpfnWndProc   = NULL;
    wc.hInstance     = hInstance;
    wc.lpszClassName = NULL;

    RegisterClass(&wc);
}


class Program
{
    public:
        static void main()
        {
            
        }

        Program(){
            main();
        }
        ~Program();
};

