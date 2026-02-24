#ifndef LITHIUM_TYPES_HH
#define LITHIUM_TYPES_HH

#if defined(_WIN32) || defined(_WIN64)
#include "Lithium-Types-Win32.hh"
#endif /* defined(_WIN32) | defined(_WIN64) */

#ifdef __FreeBSD__
#include "Lithium-Types-FreeBSD.hh"
#endif /* __FreeBSD__ */

#ifdef __linux__
#include "Lithium-Types-Linux.hh"
#endif /* __linux__ */

#endif /* LITHIUM_TYPES_HH */
