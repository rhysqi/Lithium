#include "../../../include/Lithium-System.hh"

#pragma region Windows System API Segments

#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <winuser.h>
#include <windef.h>

#pragma comment(lib, "user32.lib")

UINT Lithium_System::Util::DisplayHeight()
{
	return GetSystemMetrics(SM_CXSCREEN);
}

UINT Lithium_System::Util::DisplayWidth()
{
	return GetSystemMetrics(SM_CYSCREEN);
}

UINT Lithium_System::Util::WindowHeight(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.bottom - rect.top;
	}
	return 0;
}

UINT Lithium_System::Util::WindowWidth(HWND hWnd)
{
	RECT rect;
	if (GetWindowRect(hWnd, &rect)) {
		return rect.left - rect.right;
	}
	return 0;
}

UINT Lithium_System::Util::WindowClientHeight(HWND hWnd)
{

    return 0;
}

// Sleep with microseconds scale
VOID Lithium_System::Util::MicroSleep(UINT64 uMicroSeconds)
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

// Sleep with nanoseconds scale
VOID Lithium_System::Util::NanoSleep(UINT64 uNanoSeconds)
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

#pragma endregion Windows System API Segments

#pragma region Linux System API Segments

#ifdef __linux__

#include <sys/errno.h>

unsigned int Lithium_System::Util::ScreenHeight()
{
    
}

unsigned int Lithium_System::Util::ScreenWidth()
{

}

#endif /* __linux__ */
#pragma endregion Linux System API Segments