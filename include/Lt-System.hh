#ifndef LT_SYSTEM_HH
#define LT_SYSTEM_HH

namespace Lt_System {
	void Buffer();

	namespace Event {
		
		void New(const char *SRC);
		void Open(const char *SRC);
		void Save(const char *SRC, const char *DST);

		int Dropdown(int ComponentID);
		int Hover(int ComponentID, struct Data);
		int Slide(int ComponentID, struct Data);
	}

	namespace Shortcut {
		void Keybind(const char *Content);
	}
}

#endif /* LT_SYSTEM_HH */