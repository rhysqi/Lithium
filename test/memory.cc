#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = 4096; // 1 page
    void *mem;

    // Step 1: mmap (commit)
    mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Step 2: tulis data
    strcpy((char *)mem, "Hello World");
    printf("Before decommit: %s\n", (char *)mem);

    memset(mem, 0, size);

    // Step 5: coba baca / print
    printf("After decommit and commit: %s\n", (char *)mem);
    printf("Memory size: %lu\n", sizeof(mem));

    // Step 6: cleanup
    munmap(mem, size);
    return 0;
}
