#include "Lt-Write.h"
#include "../../include/Lt-System.hh"

int Lt_System::IO::WriteFile(const char *FileName, int SetSize, bool Action)
{
	Lt_WriteFile(FileName);
	return 0;
}