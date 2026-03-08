#include <cstdio>
#include <sys/stat.h>
#include <unistd.h>


unsigned long long Size(const char *filepath)
{
    struct stat st;

    if (!stat(filepath, &st))
        return st.st_size;

    return -1;
}

int main(int argc, const char *argv[]){
    
    const char *path = argv[1];
    
    if (path) {
        const char *msg = "File Name: %s\nSize: %llu Bytes\n";
        printf(msg, path, Size(path));
    }

    return 0;
}

