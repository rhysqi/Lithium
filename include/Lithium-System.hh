#ifndef LITHIUM_SYSTEM_HH
#define LITHIUM_SYSTEM_HH

#pragma region Windows System API Segments
#if defined(_WIN32) || defined(_WIN64)

#include "Lithium-System-Win32.hh"

#endif /* defined(_WIN32) | defined(_WIN64) */
#pragma endregion Windows System API Segments

#pragma region Linux System API Segments
#ifdef __linux__

#include "Lithium-System-Linux.hh"

#endif /* __linux__ */
#pragma endregion Linux System API Segments

#pragma region FreeBSD System API Segments
#ifdef __FreeBSD__
#include "Lithium-System-FreeBSD.hh"
#endif /* __FreeBSD__ */
#pragma endregion FreeBSD System API Segments

#endif /* LITHIUM_SYSTEM_HH */
