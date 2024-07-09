#ifndef LT_SYSTEM_HH
#define LT_SYSTEM_HH

#ifdef _WIN32

namespace Lt_System {
	namespace IO {
		int WriteFile(const char *FileName, int SetSize, bool Action);
		int ReadFile(const char *FileName, int SetSize, bool Action);
		int ExecFile(const char *FileName, int SetSize, bool Action);
	}

	namespace Thread {
		int Thread();
	}

	namespace Window {
		
	}

}


#endif /* _WIN32 */

#endif /* LT_SYSTEM_HH */