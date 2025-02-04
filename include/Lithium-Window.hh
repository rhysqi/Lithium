#ifndef LITHIUM_WINDOW_HH
#define LITHIUM_WINDOW_HH

#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>

#include <heapapi.h>
#include <uxtheme.h>

#define LT_DWM_USEDEFAULT TRUE

namespace Lithium_Window {
	// Window Style definition
	namespace DWM {
		typedef struct 
		{
			LPCWSTR lpWindowName;
			HWND hParent = NULL;
			WNDPROC wpEvent;

			UINT16 uHeight;
			UINT16 uHeightMin;
			UINT16 uHeightMax;
			UINT16 uWidth;
			UINT16 uWidthMin;
			UINT16 uWidthMax;
			
			UINT16 uPOSX = CW_USEDEFAULT;
			UINT16 uPOSY = CW_USEDEFAULT;

			BOOL bIsSessionStandalone = LT_DWM_USEDEFAULT;

			DWORD dwExStyle = 0;
			LPVOID lpScreenBuffer;
			COLORREF crfBackground;
		} Window_t, *pWindow_t;

		HWND Base(Window_t WindowData);
		HWND SystemDefault(Window_t WindowData);
		HWND SystemFlat(Window_t WindowData);
		HWND TilingMode(Window_t WindowData);
		HWND TilingModeFlat(Window_t WindowData);

		HWND Experimental(HINSTANCE hInstance);
		VOID EnableRoundedCorners(HWND hWnd);
	}

	// Event definitions
	namespace Event {
		typedef struct
		{
			LPVOID lpClientbuffer;
			LPVOID lpNonClientBuffer;
		} WindowHandler_t, *pWindowHandler_t;

		typedef struct
		{
			LPVOID lpKeyDown;
			LPVOID lpKeyUp;
			LPVOID lpKeyPress;
			LPVOID lpMouseHover;
			LPVOID lpKeyboardInput;
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

	// Widgets definitions
	namespace Widget {
		typedef struct 
		{
			LPCWSTR lpWidgetName;
			HWND hParent = NULL;
			WNDPROC wpEvent;

			UINT16 uHeight;
			UINT16 uHeightMin;
			UINT16 uHeightMax;
			UINT16 uWidth;
			UINT16 uWidthMin;
			UINT16 uWidthMax;
			
			UINT16 uPOSX = CW_USEDEFAULT;
			UINT16 uPOSY = CW_USEDEFAULT;

			BOOL bIsSessionStandalone = LT_DWM_USEDEFAULT;

			DWORD dwExStyle = 0;
			LPVOID lpWidgetBuffer;
			COLORREF crfBackground;
			COLORREF crfForeground;
		} Widget_t, *pWidget_t;

		HWND Button(Widget_t WidgetData);
		HWND Label(Widget_t WidgetData);
		HWND Menu(Widget_t WidgetData);
		HWND MenuItem(Widget_t WidgetData);
		HWND MessageBox(Widget_t WidgetData);
		HWND Overlay(Widget_t WidgetData);
		HWND RadioButton(Widget_t WidgetData);
		HWND TextBox(Widget_t WidgetData);
		HWND TreeView(Widget_t WidgetData);
	}
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* LITHIUM_WINDOW_HH */