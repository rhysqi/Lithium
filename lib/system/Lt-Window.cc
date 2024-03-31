#include "../../include/Lt-Graphics.hh"
#include "../../include/Lt-System.hh"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Windows Section
#ifdef _WIN32

#include <Windows.h>
#include <WinUser.h>
#include <wincrypt.h>


#endif /* WIN32 */

// UNIX Section
#ifdef _UNIX

#include <X11/Xlib.h>

void Window(){

}

#endif /* _UNIX */