#include <Windows.h>
#include <minwindef.h>

inline
LRESULT CALLBACK SplashWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_TIMER:
            KillTimer(hwnd, 1);
            DestroyWindow(hwnd);
            PostQuitMessage(0);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 128)); // Navy blue color
            FillRect(hdc, &ps.rcPaint, hBrush);
            DeleteObject(hBrush);
            EndPaint(hwnd, &ps);
            break;
        }
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

inline
int __fastcall Splash()
{
	HINSTANCE hInstance = NULL;
	WNDCLASS wc = {0};
    wc.lpfnWndProc = SplashWndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = "SplashScreenClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClass(&wc)) {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    int DisplayX = GetSystemMetrics(SM_CXSCREEN)/2;
    int DisplayY = GetSystemMetrics(SM_CYSCREEN)/2;

    int SplashH =  GetSystemMetrics(SM_CYSCREEN)/3;
    int SplashW = GetSystemMetrics(SM_CXSCREEN)/3;

    HWND hSplashWnd = CreateWindowExW(
        WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW,
        L"SplashScreenClass",
        NULL,
        WS_POPUP,
        DisplayX - (SplashW/2), DisplayY - (SplashH/2), SplashW, SplashH, // Position and size
        NULL, NULL, hInstance, NULL);

    if (hSplashWnd == NULL) {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    SetLayeredWindowAttributes(hSplashWnd, 0, 255, LWA_ALPHA); // Opaque window

    ShowWindow(hSplashWnd, SW_SHOW);
    UpdateWindow(hSplashWnd);

    SetTimer(hSplashWnd, 1, 5000, NULL); // Set timer for 5 seconds

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}