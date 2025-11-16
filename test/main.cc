#include <stdio.h>
#include <X11/Xlib.h>

uint ScreenWidth()
{
    return XDisplayWidth(XOpenDisplay(NULL), 0);
}

int main(int argc, const char *argv[]){
    
    printf("Screen Width: %u", ScreenWidth());
    return 0;
}