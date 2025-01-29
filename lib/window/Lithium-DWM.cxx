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

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
	
	case WM_SIZE:
        if (wParam == SIZE_MAXIMIZED) {
            // Jika jendela dimaksimalkan, ubah ukuran dan posisi jendela dengan margin
            int screenWidth = GetSystemMetrics(SM_CXMAXIMIZED); // Lebar layar
            int screenHeight = GetSystemMetrics(SM_CYMAXIMIZED); // Tinggi layar
            
            // Sesuaikan margin dan posisi jendela
            int margin = 30; // Margin yang diinginkan
            int windowWidth = screenWidth - (margin * 3);  // Ukuran jendela (lebar) dengan margin
            int windowHeight = screenHeight - (margin * 3); // Ukuran jendela (tinggi) dengan margin

            SetWindowPos(
				hWnd, HWND_TOP,
				margin, margin,
				windowWidth, windowHeight,
				SWP_NOZORDER | SWP_FRAMECHANGED
			);
        }
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			HBRUSH BackgroundColor = CreateSolidBrush(
				RGB(120, 120, 120)
			);

            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, BackgroundColor);
			
			DeleteObject(BackgroundColor);
            EndPaint(hWnd, &ps);
        }
        return 0;

    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void EnableRoundedCorners(HWND hWnd) {
    const DWORD DWMWA_WINDOW_CORNER_PREFERENCE = 33;
    int cornerPreference = DWMWCP_ROUND; // DWMNCRP_ROUND_SMALL (selalu rounded, termasuk maximized)
    DwmSetWindowAttribute(hWnd, DWMWA_WINDOW_CORNER_PREFERENCE, &cornerPreference, sizeof(cornerPreference));
}

HWND Lithium_Window::DWM::Experimental(HINSTANCE hInstance)
{
	LPCWSTR CLASS_NAME = L"Experimental_Window";
	LPCWSTR WindowName = L"Custom Window";

	WNDCLASSW wcw = { };

	wcw.lpszClassName = CLASS_NAME;
	wcw.hInstance = hInstance;
	wcw.lpfnWndProc = WindowProc;
	wcw.hbrBackground = CreateSolidBrush(RGB(0, 125, 125));

	RegisterClassW(&wcw);

	HWND hWnd = CreateWindowExW(
		0, CLASS_NAME,
		WindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 500,
		NULL, NULL, 
		hInstance, NULL
	);

	EnableRoundedCorners(hWnd);
	
	if (hWnd == NULL) {
        Lithium_System::Error::ShowLastError();
		return 0;
	}

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	
	return 0;
}

#endif /* defined(_WIN32) || defined(_WIN64) */