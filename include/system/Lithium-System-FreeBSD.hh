#ifndef LITHIUM_SYSTEM_FREEBSD_HH
#define LITHIUM_SYSTEM_FREEBSD_HH

#include <fcntl.h>

#include <stdatomic.h>
#include <sys/types.h>

#include <X11/Xlib.h>

#define LTH_SHW_MSG_GUI_MODE 1
#define LTH_SHW_MSG_CLI_MODE 0

namespace Lithium_System {

    // Directory definition
    namespace Directory {
		int Create(const char *dirname);
		int Remove(const char *dirname);
		int Rename(const char *src, char* dst);
		int Watch(const char *dirname);
    }

    // File definition
    namespace File {
		int CreateFile(const char *filename, int permission);
		int ReadFile(const char *filename);
		int WriteFile(int fd, const char *fileBuffer);
		int WatchFile(const char *filename);
    }

    // Inform definition
    namespace Inform {
		int ShowMessage(const char *message, int mode);
    }

	// Memory definition
	namespace Memory {
		
		// Heap definition
		namespace Heap {
			void Create();
		}

		// Virtual definition
		namespace Virtual {
			void Create(void *pMemory, size_t len, int iProt, int iFlags, int iFd, off_t offset);
		}
	}

    // Pool definition
    namespace Pool {
		// Memory definition
		namespace Memory {
			// Heap definition
			namespace Heap {
				void *Create(void *pMemoryPool, uint uPoolCount);
				int Free(void *pMemoryPool);
				int FreeEx(void *pMemoryPool, uint uIndex);
				int Destroy(void *pMemoryPool);
				int DestroyEx(void *pMemoryPool, uint uIndex);
				int Protect(void *pMemoryPool, int iProt, int iFlags);
				int ProtectEx(void *pMemoryPool, uint uIndex);
			}

			// Virtual definition
			namespace Virtual {

				typedef struct {
					void *addr;
					size_t len;
					int iProt;
					int iFlags;
					int fd;
					off_t offset;
				} Virtual_Pool_t, *pVirtual_Pool_t;

				void *Create(uint uPoolCount, pVirtual_Pool_t Pooling_t);
				int Free(void *pMemoryPool);
				int FreeEx(void *pMemoryPool, uint uIndex);
				int Destroy(void *pMemoryPool);
				int DestroyEx(void *pMemoryPool, uint uIndex);
				int Protect(void *pMemoryPool, int iProt, int iFlags);
				int ProtectEx(void *pMemoryPool, uint uIndex);
				int Lock(void *pMemoryPool);
				int LockEx(void *pMemoryPool, uint uIndex);
				int Unlock(void *pMemoryPool);
				int UnlockEx(void *pMemoryPool, uint uIndex);
			}
		}

		// Thread Definition
		namespace Thread {
			void Create();
			void Terminate(void *pThread);
			void TerminateEx(void *pThread, uint uIndex);
		}
	}

    // Types definition
    namespace Types {
		typedef int    *pint;
		typedef void   *pvoid;
		typedef char   *pchar;
		typedef bool   *pbool;
		typedef float  *pfloat;
		typedef double *pdouble;
    }

    namespace Util {
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

#endif /* LITHIUM_SYSTEM_FREEBSD_HH */