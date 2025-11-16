#ifndef LT_SPLASHSCREEN_HH
#define LT_SPLASHSCREEN_HH

#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Lithium-System.hh"

#include <Windows.h>
#include <winuser.h>

HWND initSplashScreen();
VOID Window_Paint(HWND hwnd);

LRESULT CALLBACK SplashWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* LT_SPLASHSCREEN_HH */