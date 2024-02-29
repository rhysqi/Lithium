#include "../../include/Lt-Graphics.hh"
#include "../../include/Lt-System.hh"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <wincrypt.h>

#ifdef _WIN32
#include <Windows.h>
#include <WinUser.h>
#endif /* WIN32 */

#ifdef _UNIX
#include <X11/Xlib.h>
#endif /* _UNIX */

void Window(){
	#ifdef _WIN32
	CRYPT_AES_256_KEY_STATE s;
	
	#endif /* _WIN32 */

	#ifdef _UNIX
	
	
	#endif /* _UNIX */
}