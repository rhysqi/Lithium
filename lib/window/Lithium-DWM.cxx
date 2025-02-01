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

#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "user32.lib")

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
            int margin = 20; // Margin yang diinginkan
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

VOID Lithium_Window::DWM::EnableRoundedCorners(HWND hWnd) {
    const DWORD DWMWA_WINDOW_CORNER_PREFERENCE = 100;
    int cornerPreference = DWMWCP_DEFAULT; // DWMNCRP_ROUND_SMALL
    DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &cornerPreference, sizeof(cornerPreference));
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

	#if ENABLE_EXTEND
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
	#endif /* ENABLE_EXTEND */

	UINT8 marg_val = 0;
	MARGINS margs = {
		marg_val, marg_val,
		marg_val , marg_val
	};
	DwmExtendFrameIntoClientArea(hWnd, &margs);
	
	if (hWnd == NULL) {
        Lithium_System::Error::ShowLastError();
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
        Lithium_System::Error::ShowLastError();
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

// System Default Window
HWND Lithium_Window::DWM::SystemDefault(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"SystemDefault_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.lpfnWndProc = WindowProc;
	wcw.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	RegisterClassW(&wcw);

	HWND hWnd;

	#if ENABLE_EXTEND
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
	#endif /* ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Error::ShowLastError();
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

// System Flat Window
HWND Lithium_Window::DWM::SystemFlat(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"SystemFlat_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.lpfnWndProc = WindowProc;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));
	RegisterClassW(&wcw);
	
	HWND hWnd;
	
	#if ENABLE_EXTEND
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
	#endif /* ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Error::ShowLastError();
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

// Tilling mode Window
HWND Lithium_Window::DWM::TilingMode(Window_t WindowData, BOOL bIsSessionStandalone)
{
	LPCWSTR CLASS_NAME = L"TilingMode_Window";
	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = NULL;
	wcw.lpfnWndProc = WindowProc;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));
	RegisterClassW(&wcw);
	
	HWND hWnd;

	#if ENABLE_EXTEND
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
	#endif /* ENABLE_EXTEND */

	if (hWnd == NULL) {
        Lithium_System::Error::ShowLastError();
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

#endif /* defined(_WIN32) || defined(_WIN64) */