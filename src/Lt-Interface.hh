#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#ifndef UNICODE
#define UNICODE
#endif /* Declare Unicode */

#include <Windows.h>
#include <WinUser.h>
#include <WinBase.h>
#endif

