#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/syscall.h>

#define BUFFER_SIZE 4096
#define NS_PER_MS   1000000L
#define NS_PER_SEC  1000000000L

static inline long
sys_write(int fd, const void *buf, unsigned long size)
{
    return syscall(SYS_write, fd, buf, size);
}

static void
print_number(long value)
{
    char buf[32];
    int i = 30;

    buf[31] = '\n';
    buf[30] = 0;

    if (value == 0) {
        buf[29] = '0';
        sys_write(1, &buf[29], 3);
        return;
    }

    while (value > 0 && i > 0) {
        buf[i--] = '0' + (value % 10);
        value /= 10;
    }

    sys_write(1, &buf[i + 1], 30 - i);
}

int
ReadFile_Buffered_MS(const char *path)
{
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes;

    struct timespec start;
    struct timespec end;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return -1;

    clock_gettime(CLOCK_MONOTONIC, &start);

    while ((bytes = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // buffer dipakai di engine Lithium
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    close(fd);

    long sec  = end.tv_sec  - start.tv_sec;
    long nsec = end.tv_nsec - start.tv_nsec;

    if (nsec < 0) {
        sec--;
        nsec += NS_PER_SEC;
    }

    long total_ns = sec * NS_PER_SEC + nsec;
    long total_ms = total_ns / NS_PER_MS;

    sys_write(1, "Load time (ms): ", 16);
    print_number(total_ms);

    return 0;
}


int main(int argc, const char *argv[]){
    
    if (argc < 2) return -1;

    ReadFile_Buffered_MS(argv[1]);

    return 0;
}