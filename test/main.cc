#include <stdarg.h>

int sum(int count, ...)
{
    va_list ap;
    va_start(ap, count);

    int total = 0;
    for(int i=0; i<count; i++)
        total += va_arg(ap, int);

    va_end(ap);
    return total;
}

int lth_main(int argc, const char *argv[]){
    
    sum(10, 100, 100);
    return 0;
}

void _start(void)
{
    long argc;
    const char **argv;

    // Ambil argc & argv dari stack (FreeBSD ABI)
    asm volatile(
        "mov %%rsp, %0"   // argc ada di [rsp]
        : "=r"(argc)
    );

    argv = (const char **)((unsigned long *)__builtin_frame_address(0) + 1);

    // panggil fungsi utama kamu
    int ret = lth_main((int)argc, argv);

    // lakukan syscall exit
    asm volatile(
        "movq $1, %%rax\n"    // SYS_exit = 1 (FreeBSD)
        "movq %0, %%rdi\n"    // exit code (rdi)
        "syscall\n"
        :
        : "r"(ret)
        : "%rax", "%rdi"
    );

    while (1) {} // jaga agar tidak jatuh ke area tak valid
}