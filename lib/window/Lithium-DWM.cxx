#include <cstddef>
#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include "../../include/Lithium-System.hh"
#include "../../include/Lithium-Window.hh"

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>

#include <wingdi.h>
#include <windef.h>
#include <minwindef.h>
#include <dwmapi.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "dwmapi.lib")

LRESULT CALLBACK Base_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SystemDefault_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK SystemFlat_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TilingMode_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK TilingModeFlat_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

VOID Lithium_Window::DWM::EnableRoundedCorners(HWND hWnd) {
    const DWORD DWMWA_WINDOW_CORNER_PREFERENCE = 100;
    int cornerPreference = DWMWCP_DEFAULT; // DWMNCRP_ROUND_SMALL
    DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &cornerPreference, sizeof(cornerPreference));
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
	
	case WM_SIZE:
        if (wParam == SIZE_MAXIMIZED) {
            // If window maximiazed, changes size and add some gap with margins
            int screenWidth = GetSystemMetrics(SM_CXMAXIMIZED); // Screen width
            int screenHeight = GetSystemMetrics(SM_CYMAXIMIZED); // Screen height
            
            // Setup margins
            int margin = 20; // Margin size
            int windowWidth = screenWidth - (margin * 3);  // Window size (width) with margins
            int windowHeight = screenHeight - (margin * 3); // Window size (height) with margins

            SetWindowPos(
				hwnd, HWND_TOP,
				margin, margin,
				windowWidth, windowHeight,
				SWP_NOZORDER | SWP_FRAMECHANGED
			);
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

			HBRUSH BackgroundColor = CreateSolidBrush(
				RGB(120, 120, 120)
			);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, BackgroundColor);
			
			DeleteObject(BackgroundColor);
            EndPaint(hwnd, &ps);
        }
        return 0;
	}
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

HWND Lithium_Window::DWM::Experimental(HINSTANCE hInstance)
{
	LPCWSTR CLASS_NAME = L"Experimental_Window";
	LPCWSTR WindowName = L"Custom Window";

	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.lpfnWndProc = WindowProc;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));

	RegisterClassW(&wcw);

	HWND hWnd;

	#if WINDOW_ENABLE_EXTEND
	hWnd = CreateWindowExW(
		0, CLASS_NAME,
		WindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		hInstance, NULL
	);

	#else
	hWnd = CreateWindowW(
		CLASS_NAME,
		WindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		hInstance, NULL
	);
	#endif /* WINDOW_ENABLE_EXTEND */

	UINT8 marg_val = 0;
	MARGINS margs = {
		marg_val, marg_val,
		marg_val , marg_val
	};
	DwmExtendFrameIntoClientArea(hWnd, &margs);
	
	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	
	return hWnd;
}

// Lithium Base Window
HWND Lithium_Window::DWM::Base(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"Base_Window";

	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;

	wcw.lpfnWndProc = Base_WinProc;
	if (WindowData.wpEvent) {
		wcw.lpfnWndProc = WindowData.wpEvent;
	}

	HWND hWnd;

	hWnd = CreateWindowW(
		CLASS_NAME, WindowData.lpWindowName,
		WS_OVERLAPPEDWINDOW,
		WindowData.uPOSX, WindowData.uPOSY,
		WindowData.uWidth, WindowData.uHeight,
		WindowData.hwParent, NULL,
		NULL, NULL
	);

	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	if (bIsSessionStandalone || NULL) {
		MSG msg = { };
		while (GetMessageW(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return nullptr;
	}

	return hWnd;
}

// System Default Window
HWND Lithium_Window::DWM::SystemDefault(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"SystemDefault_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wcw.lpfnWndProc = SystemDefault_WinProc;

	if (WindowData.wpEvent) {
		wcw.lpfnWndProc = WindowData.wpEvent;
	}

	RegisterClassW(&wcw);

	HWND hWnd;

	#if WINDOW_ENABLE_EXTEND
	hWnd = CreateWindowExW(
		0, CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);

	#else
	hWnd = CreateWindowW(
		CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);
	#endif /* WINDOW_ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	if (bIsSessionStandalone || NULL) {
		MSG msg = { };
		while (GetMessageW(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return nullptr;
	}

	return hWnd;
}

// System Flat Window
HWND Lithium_Window::DWM::SystemFlat(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"SystemFlat_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));
	wcw.lpfnWndProc = SystemFlat_WinProc;

	if (WindowData.wpEvent) {
		wcw.lpfnWndProc = WindowData.wpEvent;
	}
	
	RegisterClassW(&wcw);

	HWND hWnd;
	
	#if WINDOW_ENABLE_EXTEND
	hWnd = CreateWindowExW(
		0, CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL,
		NULL, NULL
	);

	#else
	hWnd = CreateWindowW(
		CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);
	#endif /* WINDOW_ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	if (bIsSessionStandalone || NULL) {
		MSG msg = { };
		while (GetMessageW(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return nullptr;
	}

	return hWnd;
}

// Tilling mode Window
HWND Lithium_Window::DWM::TilingMode(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"TilingMode_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));
	wcw.lpfnWndProc = TilingMode_WinProc;

	if (WindowData.wpEvent) {
		wcw.lpfnWndProc = WindowData.wpEvent;
	}

	RegisterClassW(&wcw);
	
	HWND hWnd;

	#if WINDOW_ENABLE_EXTEND
	hWnd = CreateWindowExW(
		0, CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);

	#else
	hWnd = CreateWindowW(
		CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);
	#endif /* WINDOW_ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	if (bIsSessionStandalone || NULL) {
		MSG msg = { };
		while (GetMessageW(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return nullptr;
	}

	return hWnd;
}

HWND Lithium_Window::DWM::TilingModeFlat(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"TilingModeFlat_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));
	wcw.lpfnWndProc = TilingMode_WinProc;
	
	if (WindowData.wpEvent) {
		wcw.lpfnWndProc = WindowData.wpEvent;
	}

	RegisterClassW(&wcw);
	
	HWND hWnd;

	#if WINDOW_ENABLE_EXTEND
	hWnd = CreateWindowExW(
		WindowData.dwExStyle, CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);

	#else
	hWnd = CreateWindowW(
		CLASS_NAME,
		WindowData.lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		NULL, NULL
	);
	#endif /* WINDOW_ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
		return 0;
	}

	if (bIsSessionStandalone) {
		MSG msg = { };
		while (GetMessageW(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return nullptr;
	}

	return hWnd;
}


// Default Base Window Process
LRESULT CALLBACK Base_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Default SystemDefault Window Process
LRESULT CALLBACK SystemDefault_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Default SystemFlat Window Process
LRESULT CALLBACK SystemFlat_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Default Tiling Mode Window Process
LRESULT CALLBACK TilingMode_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;

		case WM_SIZE:
			if (wParam == SIZE_MAXIMIZED) {
				// If window maximiazed, changes size and add some gap with margins
				INT screenWidth = GetSystemMetrics(SM_CXMAXIMIZED); // Screen width
				INT screenHeight = GetSystemMetrics(SM_CYMAXIMIZED); // Screen height
				
				// Setup margins
				INT margin = 20; // Margin size
				INT windowWidth = screenWidth - (margin * 3);  // Window size (width) with margins
				INT windowHeight = screenHeight - (margin * 3); // Window size (height) with margins

				SetWindowPos(
					hwnd, HWND_TOP,
					margin, margin,
					windowWidth, windowHeight,
					SWP_NOZORDER | SWP_FRAMECHANGED
				);
			}
			break;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Default Tiling Flat Mode Window Process
LRESULT CALLBACK TilingModeFlat_WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) 
	{
		case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));
            EndPaint(hwnd, &ps);
        }
        return 0;

		case WM_SIZE:
			if (wParam == SIZE_MAXIMIZED) {
				// If window maximiazed, changes size and add some gap with margins
				INT screenWidth = GetSystemMetrics(SM_CXMAXIMIZED); // Screen width
				INT screenHeight = GetSystemMetrics(SM_CYMAXIMIZED); // Screen height
				
				// Setup margins
				INT margin = 20; // Margin size
				INT windowWidth = screenWidth - (margin * 3);  // Window size (width) with margins
				INT windowHeight = screenHeight - (margin * 3); // Window size (height) with margins

				SetWindowPos(
					hwnd, HWND_TOP,
					margin, margin,
					windowWidth, windowHeight,
					SWP_NOZORDER | SWP_FRAMECHANGED
				);
			}
			break;

		case WM_NCCALCSIZE: {
			NCCALCSIZE_PARAMS *npcp = (NCCALCSIZE_PARAMS*)lParam;
			npcp->rgrc[0].top = 0;
		}
		
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

#endif /* defined(_WIN32) || defined(_WIN64) */