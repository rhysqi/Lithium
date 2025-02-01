#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include "../../include/Lithium-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <windef.h>

using namespace Lithium_System;

UINT Util::DisplayHeight()
{
	return GetSystemMetrics(SM_CXSCREEN);
}

UINT Util::DisplayWidth()
{
	return GetSystemMetrics(SM_CYSCREEN);
}

UINT Util::WindowHeight(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.bottom - rect.top;
	}
	return 0;
}

UINT Util::WindowWidth(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.left - rect.right;
	}
	return 0;
}

VOID Util::MicroSleep(UINT64 uMicroSeconds)
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    UINT64 targetTicks = uMicroSeconds * frequency.QuadPart / 1000000;

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    
    LARGE_INTEGER current;
    do {
        QueryPerformanceCounter(&current); 
    } while ((current.QuadPart - start.QuadPart) < targetTicks);
}

VOID Util::NanoSleep(UINT64 uNanoSeconds)
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    UINT64 targetTicks = uNanoSeconds * frequency.QuadPart / 1000000000;

    LARGE_INTEGER start;
    QueryPerformanceCounter(&start);
    
    LARGE_INTEGER current;
    do {
        QueryPerformanceCounter(&current); 
    } while ((current.QuadPart - start.QuadPart) < targetTicks);
}

#endif /* defined(_WIN32) || defined(_WIN64) */