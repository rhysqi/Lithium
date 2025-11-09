#ifndef LITHIUM_SYSTEM_FREEBSD_HH
#define LITHIUM_SYSTEM_FREEBSD_HH

#include <X11/Xlib.h>

namespace Lithium_System {

    // Directory definition
    namespace Directory {

    }

    // File definition
    namespace File {
	int CreateFile(const char *filename);
	int ReadFile(const char *filename);
	int WriteFile(const char *filename, const char *fileBuffer);
    } // namespace File

    // Inform definition
    namespace Inform {
	int ShowLastError();
	int ShowMessage(const char *message);
    } // namespace Inform

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
	} // namespace Memory

	namespace Thread {

	}
    } // namespace Pool

    // Types definition
    namespace Types {
	typedef int    *pint;
	typedef void   *pvoid;
	typedef char   *pchar;
	typedef bool   *pbool;
	typedef float  *pfloat;
	typedef double *pdouble;
    } // namespace Types

    namespace Utils {
	bool SSE42_Support();
	bool AVX2_Support();
	bool GPU_Enums();
	bool Debugger();

	unsigned int ScreenHeight();
	unsigned int ScreenWidth();

	unsigned int WindowHeight(Window window);
	unsigned int WindowWidth(Window window);
    } // namespace Utils
} // namespace Lithium_System

#endif /* LITHIUM_SYSTEM_FREEBSD_HH */
