#include <X11/Xlib.h>
#include <cstdio>

unsigned int ScreenHeight()
{
    Display *dsp = XOpenDisplay(NULL);
    if (!dsp) return 1;

    unsigned int res = DisplayHeight(dsp, 0);
    XCloseDisplay(dsp);
    
    return res;
}

int main(int argc, const char *argv[]){
    
    printf("Window height: %d\n", ScreenHeight());
    
    return 0;
}