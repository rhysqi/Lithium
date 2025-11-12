#include "../../include/Lithium-System.hh"
#include <sys/types.h>

#if defined(_WIN32) || defined(_WIN64)


#endif /* defined(_WIN32) || defined(_WIN64) */

#ifdef __linux__

#include <stdio.h>
#include <sys/file.h>

int Lithium_System::File::Create(const char *filename)
{
	if (!fopen(filename, "w")) {
		printf("Failed to create file: %s\n", filename);
		return -1;
	}

	return 0;
}

#endif /* __linux__ */