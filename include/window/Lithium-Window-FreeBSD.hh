#ifndef LITHIUM_WINDOW_FREEBSD_HH
#define LITHIUM_WINDOW_FREEBSD_HH

#include "../types/Lithium-Types.hh"

namespace Lithium_Window {
    using namespace Lithium_Types; 

    namespace Util {
        unsigned int ScreenHeight();
		unsigned int ScreenWidth();

		unsigned int WindowHeight(pWindow_t window);
		unsigned int WindowWidth(pWindow_t window);
    }
}

#endif /* LITHIUM_WINDOW_FREEBSD_HH */