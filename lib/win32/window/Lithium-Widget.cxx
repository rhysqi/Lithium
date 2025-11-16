#if defined(_WIN32) || defined(_WIN64)

#include "../../../include/window/Lithium-Window-Win32.hh"

#include <Windows.h>
#include <winuser.h>
#include <winnt.h>

HWND Lithium_Window::Widget::Menu(Widget_t ltMenuData)
{

	return 0;
}

#endif /* defined(_WIN32) || defined(_WIN64) */