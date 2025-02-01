#ifndef LITHIUM_SYSTEM_HH
#define LITHIUM_SYSTEM_HH

#if defined(_WIN32) | defined(_WIN64)

#include <Windows.h>
#include <winnt.h>

#define WDS_USEDEFAULT 

namespace Lithium_System {
	// Diagnostic definition
	namespace Diagnostic {
		HANDLE FileWatcher(LPCWSTR lpFilepath);
		HANDLE CPU_Usage_Global(UINT32 uIntervalMiliSeconds);
		HANDLE CPU_Usage_Local(UINT32 uIntervalMiliSeconds, HWND hWnd);
	}

	// Directory definition
	namespace Directory {
		HANDLE Create(LPCWSTR lpDirName, LPSECURITY_ATTRIBUTES saAttrSec);
		HANDLE Remove(LPCWSTR lpDirName);
	}

	// File definition
	namespace File {
		HANDLE Create(LPCWSTR FileName, LPSECURITY_ATTRIBUTES AttrSec, DWORD dwFlagsAndAttribute);

		HANDLE CreateMapping();

		BOOL Read(LPCWSTR FileName);
		BOOL ReadEx(LPCWSTR FileName);

		BOOL Write(HANDLE hFile, LPCWSTR lpFileBuffer);
		BOOL WriteEx(HANDLE hFile, LPCWSTR lpFileBuffer);
	}

	// Inform definition
	namespace Inform {
		INT ShowLastError();
		INT ShowMessage(LPCWSTR lpMessage);
	}

	// Utililty definition
	namespace Util {
		UINT DisplayHeight();
		UINT DisplayWidth();

		UINT WindowClientHeight(HWND hWnd);
		UINT WindowClientWidth(HWND hWnd);

		UINT WindowHeight(HWND hWnd);
		UINT WindowWidth(HWND hWnd);

		VOID MicroSleep(UINT64 uMicroSeconds);
		VOID NanoSleep(UINT64 uNanoSeconds);
	}
}

#endif /* defined(_WIN32) | defined(_WIN64) */
#endif /* LITHIUM_SYSTEM_HH */