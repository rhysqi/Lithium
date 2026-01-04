#include "../../../include/system/Lithium-System-Win32.hh"

#pragma region Windows System API Segments
#if defined(_WIN32) || defined(_WIN64)

#ifndef UNICODE
#define UNICODE
#endif /* UNICODE */

#include <winnt.h>

#include <handleapi.h>
#include <heapapi.h>
#include <memoryapi.h>

LPVOID Aero_System::Pool::Memory::Virtual::Create(INT PoolCount, LPVOID lpMemoryInit)
{
    LPVOID  hMemory = lpMemoryInit;
    LPVOID *hPool =
	(LPVOID *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(LPVOID) * PoolCount);

    for (INT MemCounter = 0; MemCounter < PoolCount; ++MemCounter)
	{

	    hPool[MemCounter] = hMemory;
	    if (!hMemory)
		{
		    Aero_System::Inform::ShowLastError();
		    return nullptr;
	    }
	}

    return (LPVOID)hPool;
}

#endif /* defined(_WIN32) || defined(_WIN64) */
#pragma endregion Windows System API Segments

#pragma region Linux System API Segments
#ifdef __linux__

#include <sys/mman.h>

using namespace Lithium_System::Types;

pvoid Lithium_System::Pool::Memory::Virtual::Create()
{

    return nullptr;
}

#endif /* __linux__ */
#pragma endregion Linux System API Segments

#pragma region FreeBSD System API Segments

#include <sys/mman.h>
#include <sys/vmem.h>
#include <sys/event.h>

using namespace Lithium_System::Types;

// Heap Pool Allocation
pvoid Lithium_System::Pool::Memory::Heap::Create()
{
	// mmap
	return (pvoid)0;
}

// Virtual Memory Pool Allocation
pvoid Lithium_System::Pool::Memory::Virtual::Create()
{
	return (pvoid)0;
}

#pragma endregion FreeBSD System API Segments