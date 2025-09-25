#include "../../include/Lithium-Graphics.hh"

#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <Windows.h>
#include <wingdi.h>

#pragma comment(lib, "gdi32.lib")

HBRUSH Lithium_Graphics::Color::CreateBrushFromHex(COLORREF hexColor) 
{
    BYTE r = (hexColor >> 16) & 0xFF;
    BYTE g = (hexColor >> 8) & 0xFF;
    BYTE b = hexColor & 0xFF;
    return CreateSolidBrush(RGB(r, g, b));
}

HBRUSH Lithium_Graphics::Color::CreateBrushFromRGB(UINT8 Red, UINT8 Green, UINT8 Blue)
{
    return CreateSolidBrush(RGB(Red, Green, Blue));
}

COLORREF Lithium_Graphics::Color::Hex_RGB(COLORREF hexColor)
{
	BYTE R = (hexColor >> 16) & 0xff;
	BYTE G = (hexColor >> 8) & 0xff;
	BYTE B = (hexColor) & 0xff;
	return RGB(R, G, B);
}

#endif /* defined(_WIN32) || defined(_WIN64) */

#ifdef __linux__

#include <X11/Xlib.h>



#endif /* __linux__ */

#ifdef __FreeBSD__

#include <X11/Xlib.h>


#endif /* __FreeBSD__ */