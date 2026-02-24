#include "../../../include/Lithium.hh"

const unsigned long long sfr_Chunk_t = 5 * 1024 * 1024ULL;

void File_Dynamic_Read(const char *filepath);

void File_Dynamic_Write(const char *filepath);

int File_Buffer_Read(const char *filepath);
int File_Buffer_Write(const char *filepath);

