#ifndef LITHIUM_SYSTEM_HH
#define LITHIUM_SYSTEM_HH

#if defined(_WIN32) || defined(_WIN64)
#include "Lithium-System-Win32.hh"
#endif /* defined(_WIN32) | defined(_WIN64) */

#ifdef __FreeBSD__
#include "Lithium-System-FreeBSD.hh"
#endif /* __FreeBSD__ */

#ifdef __linux__
#include "Lithium-System-Linux.hh"
#endif /* __linux__ */

#endif /* LITHIUM_SYSTEM_HH */
