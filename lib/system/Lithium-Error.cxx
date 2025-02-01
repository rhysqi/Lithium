#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Lithium-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winbase.h>
#include <winnt.h>

#include <errhandlingapi.h>
#include <minwinbase.h>

// Aero system error message with messagebox
INT Lithium_System::Error::ShowLastError()
{
	DWORD errorCode = GetLastError();
	WCHAR systemErrorMessage[512];
	WCHAR fullErrorMessage[1024] = { 0 };

	FormatMessageW(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorCode, 0,
		systemErrorMessage,
		sizeof(systemErrorMessage) / sizeof(WCHAR),
		NULL
	);

	lstrcatW(fullErrorMessage, L"System Error Message:\n");
	lstrcatW(fullErrorMessage, systemErrorMessage);
	lstrcatW(fullErrorMessage,L"\0");

	return MessageBoxW(NULL, fullErrorMessage, L"Error Code", MB_OK | MB_ICONERROR);
}

#endif /* defined(_WIN32) || defined(_WIN64) */