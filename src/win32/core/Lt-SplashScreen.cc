#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include "Lt-SplashScreen.hh"

HWND initSplashScreen()
{
	INT SizeHeight = 500;
	INT SizeWeidth = 800;

	INT DspHeight = Lithium_System::Util::DisplayHeight();
	INT DspWidth = Lithium_System::Util::DisplayWidth();

	HINSTANCE hInstance = NULL;
	WNDCLASS wc = {0};
    wc.lpfnWndProc = SplashWndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"SplashScreenClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClass(&wc)) {
        Lithium_System::Inform::ShowLastError();
        return 0;
    }

	INT PosX = DspWidth / 2;
	INT PosY = DspHeight / 2;

	HWND hSplashWnd = CreateWindowExW(
        WS_EX_TOOLWINDOW | WS_EX_LAYERED,
        L"SplashScreenClass\0",
        NULL,
        WS_POPUP | WS_OVERLAPPED,
        PosX - (SizeWeidth / 2), PosY - (SizeHeight / 2), // Position
        SizeWeidth, SizeHeight, // Size
        NULL, NULL, hInstance, NULL);

	if (hSplashWnd == NULL) {
        Lithium_System::Inform::ShowLastError();
        return 0;
    }

	// Set the window region to a rounded rectangle
    HRGN hRgn = CreateRoundRectRgn(0, 0, SizeWeidth, SizeHeight, 25, 25); // Adjust the last two parameters for roundness
    SetWindowRgn(hSplashWnd, hRgn, TRUE);

    // Alpha Color
    SetLayeredWindowAttributes(hSplashWnd, 0, 255, LWA_ALPHA); // Opaque window
    ShowWindow(hSplashWnd, SW_SHOW);
    UpdateWindow(hSplashWnd);

    SetTimer(hSplashWnd, 1, 5000, NULL); // Set timer for 5 seconds

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 9)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

    return 0;
}

LRESULT CALLBACK
SplashWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_TIMER: {
            KillTimer(hwnd, 1);
            DestroyWindow(hwnd);
            PostQuitMessage(0);
            break;
        }
            
        case WM_PAINT: {
            Window_Paint(hwnd);
            break;
        }

        case WM_NCHITTEST: {
            LRESULT hit = DefWindowProc(hwnd, msg, wParam, lParam);
            if (hit == HTCLIENT) {
                // Treat all client area clicks as clicks on the title bar (allow dragging)
                return HTCAPTION;
            }
            return hit;
        }
            
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

VOID Window_Paint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    HBRUSH hBrush = CreateSolidBrush(0xffffff); // Navy blue color

    FillRect(hdc, &ps.rcPaint, hBrush);
    DeleteObject(hBrush);
    EndPaint(hwnd, &ps);
}

#endif /* defined(_WIN32) || defined(_WIN64) */