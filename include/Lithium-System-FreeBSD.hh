
#include <X11/Xlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>

namespace Lithium_System {

    // Directory definition
    namespace Directory {
		int Create(const char *dirname);
		int Remove(const char *src, char* dst);
		int Rename(const char *src, char* dst);
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
		int ShowMessage(const char *message, int mode);
    } // namespace Inform

    // Pool definition
    namespace Pool {
		// Memory definition
		namespace Memory {
			// Heap definition
			namespace Heap {
				void *Create();
				void *Free(void* pMemoryPool);
				void *FreeEx(void* pMemoryPool, uint uIndex);
				void *Destroy(void* pMemoryPool);
				void *DestroyEx(void* pMemoryPool, uint uIndex);
			}

			// Virtual definition
			namespace Virtual {
				void *Create();
				void Free(void* pMemoryPool);
				void FreeEx(void* pMemoryPool, uint uIndex);
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

    namespace Util {
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
