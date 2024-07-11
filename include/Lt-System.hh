#ifndef LT_SYSTEM_HH
#define LT_SYSTEM_HH

#ifdef _WIN32

#define KeyPress 0x001211
#define KeyRelease 0x001212
#define KeyContinous 0x001213

namespace Lt_System {
	namespace IO {
		int WriteFile(const char *FileName, int SetSize, bool Action);
		int ReadFile(const char *FileName, int SetSize, bool Action);
		int ExecFile(const char *FileName, int SetSize, bool Action);
	}

	namespace Event {
		void Key_Entry(int KeyHC, int OnAction);
		void Shortcut();
	}

	namespace Thread {
		int CreateThread(int ProcID);
		int ChildThread(int ProcID, int ProcParent);
		int TerminateThread(int ProcID);
	}

	namespace Window {
		int CreateWindow();
		int ChildWindow();
		int TerminateWindows();
	}

}

#endif /* _WIN32 */

#endif /* LT_SYSTEM_HH */