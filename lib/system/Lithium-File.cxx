#include "../../include/Lithium-System.hh"

#if defined(_WIN32) || defined(_WIN64)


#endif /* defined(_WIN32) || defined(_WIN64) */

#ifdef __linux__

#include <sys/file.h>

int Lithium_System::File::CreateFile(const char *filename)
{
	
	return 0;
}

#endif /* __linux__ */