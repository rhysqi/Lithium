#if defined(_WIN32) || defined(_WIN64)

#include "../../include/Lithium-System.hh"

#include <Windows.h>
#include <winuser.h>
#include <winbase.h>
#include <winnt.h>

#include <errhandlingapi.h>
#include <minwinbase.h>

// Lithium system error message with messagebox but not terminated process
INT Lithium_System::Inform::ShowErrorWithoutTerminate()
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

// Lithium system error message with messagebox
INT Lithium_System::Inform::ShowLastError()
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

	MessageBoxW(NULL, fullErrorMessage, L"Error Code", MB_OK | MB_ICONERROR);
	ExitProcess(0);
	return 0;
}

// Lithium system message with messagebox
INT Lithium_System::Inform::ShowMessage(LPCWSTR lpMessage)
{
	if (!lpMessage) {
		lpMessage = L"Message are null or not initialized";
	}
	
	return MessageBoxW(NULL, lpMessage, L"Inform Message", MB_OK | MB_ICONINFORMATION);
}

#endif /* defined(_WIN32) || defined(_WIN64) */