#ifndef LITHIUM_SYSTEM_HH
#define LITHIUM_SYSTEM_HH

#pragma region Windows System API Segments
#if defined(_WIN32) || defined(_WIN64)

#include <Windows.h>
#include <winnt.h>

// #define WDS_USEDEFAULT

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

		BOOL Read(LPCWSTR FileName);
		BOOL ReadEx(LPCWSTR FileName);

		BOOL Write(HANDLE hFile, LPCWSTR lpFileBuffer);
		BOOL WriteEx(HANDLE hFile, LPCWSTR lpFileBuffer);
    }

    // Inform definition
    namespace Inform {
		INT ShowErrorWithoutTerminate();
		INT ShowLastError();
		INT ShowMessage(LPCWSTR lpMessage);
    }

	// Pool definition
	namespace Pool {

		// Memory definition
		namespace Memory {

			// Heap definition
			namespace Heap {
				typedef struct {
					LPVOID lpMemoryPool;
					INT PoolCount;
					UINT uOffset;
				} Heap_Pool_t, *pHeap_Pool_t;

				LPVOID Create(INT PoolCount, pHeap_Pool_t pHeapPool);
				UINT CountPool(LPVOID lpMemoryPool);
				LPVOID Peek(LPVOID lpMemoryPool, UINT uIndex);

				BOOL Lock(LPVOID lpMemoryPool);
				BOOL LockEx(LPVOID lpMemoryPool, UINT uIndex);
				BOOL Unlock(LPVOID lpMemoryPool);
				BOOL UnlockEx(LPVOID lpMemoryPool, UINT uIndex);
				BOOL Free(LPVOID lpMemoryPool);
				BOOL Destroy(LPVOID lpMemoryPool);
			}

			// Virtual definition
			namespace Virtual {
				typedef struct {
					LPVOID lpAddress;
					SIZE_T dwSize;
					DWORD dwProtection;
					DWORD flAllocationType;
					UINT uOffset;
				} Virtual_Pool_t, *pVirtual_Pool_t;

				LPVOID Create(INT PoolCount, pVirtual_Pool_t pVirtualPool);
				UINT CountPool(LPVOID lpMemoryPool);
				LPVOID Peek(LPVOID lpMemoryPool, UINT uIndex);

				BOOL Protect(LPVOID lpMemoryPool, DWORD dwProtection);
				BOOL Lock(LPVOID lpMemoryPool);
				BOOL LockEx(LPVOID lpMemoryPool, UINT uIndex);
				BOOL Unlock(LPVOID lpMemoryPool);
				BOOL UnlockEx(LPVOID lpMemoryPool, UINT uIndex);
				BOOL Free(LPVOID lpMemoryPool);
				BOOL Destroy(LPVOID lpMemoryPool);
			}
		}

		// Thread definition
		namespace Thread {
			// Implement later
		}
	}

	// Types definition
	namespace Types {
		typedef LPINT *LPPINT;
		typedef LPBOOL *LPPBOOL;
		typedef LPCSTR *LPPCSTR;
		typedef LPCWSTR *LPPCWSTR;
		typedef LPVOID *LPPVOID;
		typedef LPWORD *LPPWORD;
		typedef LPBYTE *LPPBYTE;
		
		typedef PINT *PPINT;
		typedef PFLOAT *PPFLOAT;
		typedef PBOOL *PPBOOL;
		typedef PCHAR *PPCHAR;
		typedef PSTR *PPSTR;
		typedef PWCHAR *PPWCHAR;
		typedef PVOID *PPVOID;
		typedef PWORD *PPWORD;
		typedef PBYTE *PPBYTE;
	}

    // Utility definition
    namespace Util {
		LPVOID CheckFileBasedOnMagicNumber(LPCWSTR lpFilepath);
		LPVOID CheckFileBasedOnFormat(LPCWSTR lpFilepath);

		UINT DisplayHeight();
		UINT DisplayWidth();

		UINT WindowHeight(HWND hWnd);
		UINT WindowWidth(HWND hWnd);

		VOID MicroSleep(UINT64 uMicroSeconds);
		VOID NanoSleep(UINT64 uNanoSeconds);
    }
}

#endif /* defined(_WIN32) | defined(_WIN64) */
#pragma endregion Windows System API Segments

#pragma region Linux System API Segments
#ifdef __linux__

#include <X11/Xlib.h>

#include <sys/types.h>

namespace Lithium_System {

	// Directory definition
	namespace Directory {
		
	}

	// File definition
	namespace File {
		int CreateFile(const char* filename);
		int ReadFile(const char* filename);
		int WriteFile(const char* filename, const char* fileBuffer);
	}

	// Inform definition
	namespace Inform {
		int ShowLastError();
		int ShowMessage(const char* message);
	}

	// Pool definition
	namespace Pool {

		// Memory definition
		namespace Memory {

			// Heap definition
			namespace Heap {
				void *Create();
			}

			// Virtual definition
			namespace Virtual {
				void *Create();
				uint CountPool(void *pMemoryPool);
				void *Peek(void *pMemoryPool, unsigned int uIndex);

				bool Lock(void *pMemoryPool);
			}
		}

		namespace Thread {

		}
	}

	// Types definition
	namespace Types {
		typedef int *pint;
		typedef void *pvoid;
		typedef char *pchar;
		typedef bool *pbool;
		typedef float *pfloat;
		typedef double *pdouble;
	}
	
	namespace Utils {
		bool SSE42_Support();
		bool AVX2_Support();
		bool GPU_Enums();
		bool Debugger();
		
		unsigned int ScreenHeight();
		unsigned int ScreenWidth();

		unsigned int WindowHeight(Window window);
		unsigned int WindowWidth(Window window);
	}
}

#endif /* __linux__ */
#pragma endregion Linux System API Segments

#pragma region FreeBSD System API Segments
#ifdef __FreeBSD__

#include <X11/Xlib.h>

namespace Lithium_System {

	// Directory definition
	namespace Directory {
		
	}

	// File definition
	namespace File {
		int CreateFile(const char* filename);
		int ReadFile(const char* filename);
		int WriteFile(const char* filename, const char* fileBuffer);
	}

	// Inform definition
	namespace Inform {
		int ShowLastError();
		int ShowMessage(const char* message);
	}

	// Pool definition
	namespace Pool {

		// Memory definition
		namespace Memory {

			// Heap definition
			namespace Heap {
				void *Create();
			}

			// Virtual definition
			namespace Virtual {
				void *Create();
			}
		}

		namespace Thread {

		}
	}

	// Types definition
	namespace Types {
		typedef int *pint;
		typedef void *pvoid;
		typedef char *pchar;
		typedef bool *pbool;
		typedef float *pfloat;
		typedef double *pdouble;
	}

	namespace Utils {
		bool SSE42_Support();
		bool AVX2_Support();
		bool GPU_Enums();
		bool Debugger();

		unsigned int ScreenHeight();
		unsigned int ScreenWidth();

		unsigned int WindowHeight(Window window);
		unsigned int WindowWidth(Window window);
	}
}

#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments

#endif /* LITHIUM_SYSTEM_HH */