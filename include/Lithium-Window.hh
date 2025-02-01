#ifndef LITHIUM_WINDOW_HH
#define LITHIUM_WINDOW_HH

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>

#include <heapapi.h>
#include <uxtheme.h>

#define LT_DWM_USEDEFAULT 0

namespace Lithium_Window {
	// Window Style definition
	namespace DWM {
		typedef struct 
		{
			LPCWSTR lpWindowName;
			HWND hwParent;
			WNDPROC wpEvent;

			UINT16 uHeight;
			UINT16 uWidth;
			UINT16 uPOSX;
			UINT16 uPOSY;

			LPVOID lpScreenBuffer;
			COLORREF crfBackground;
		} Window_t, *pWindow_t;

		HWND Base(Window_t WindowData, BOOL bIsSessionStandalone);
		HWND SystemDefault(Window_t WindowData, BOOL bIsSessionStandalone);
		HWND SystemFlat(Window_t WindowData, BOOL bIsSessionStandalone);
		HWND TilingMode(Window_t WindowData, BOOL bIsSessionStandalone);

		HWND Experimental(HINSTANCE hInstance);
		VOID EnableRoundedCorners(HWND hWnd);
	}

	// Event definitions
	namespace Event {
		typedef struct
		{
			LPVOID lpClientbuffer;
			LPVOID lpNClientBuffer;
		} WindowHandler_t, *pWindowHandler_t;

		typedef struct
		{
			LPVOID lpKeyDown;
			LPVOID lpKeyUp;
			LPVOID lpKeyPress;
		} WdigetHandler_t, *pWdigetHandler_t;
	}

	// Layout definitions
	namespace Layout {
		typedef struct
		{
			INT16 Height;
			INT16 Width;
			INT16 gap;
			INT16 thickness;
			
			MARGINS margins;
			MARGINS paddings;
		} Layout_t, *pLayout_t;

		LPVOID Grid(Layout_t ltGrid);
		LPVOID GridSplitter(Layout_t ltGridSplitter);
		LPVOID StackPanel(Layout_t ltStackPanel);
		LPVOID WrapPanel(Layout_t ltWrapPanel);
	}

	// Wdigets definitions
	namespace Widget {
		HWND Button(LPCWSTR lpButtonName, DWORD dwButtonStyle, WNDPROC wpEvent);
		HWND Menu();
		HWND TextBox();
		HWND TreeView();
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* LITHIUM_WINDOW_HH */