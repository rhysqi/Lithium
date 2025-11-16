#ifndef LITHIUM_WINDOW_HH
#define LITHIUM_WINDOW_HH

#if defined(_WIN32) || defined(_WIN64)
#include "Lithium-Window-Win32.hh"
#endif /* defined(_WIN32) || defined(_WIN64) */

#ifdef __FreeBSD__
#include "Lithium-Window-FreeBSD.hh"
#endif /* __FreeBSD__ */

#ifdef __linux__
#include "Lithium-Window-Linux.hh"
#endif /* __linux__ */

#endif /* LITHIUM_WINDOW_HH */
