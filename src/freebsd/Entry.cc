extern "C" void Lth_Start(int argc, char **argv);
extern "C" int  Lth_Entry(int argc, const char *argv[]);

// extern "C" void Lth_Start()
// {
//     int argc;
//     const char **argv;

//     __asm__ volatile(
//         "mov (%%rsp), %0\n"
//         "lea 8(%%rsp), %1\n"
//         : "=r"(argc), "=r"(argv)
//         :
//         : "memory"
//     );

//     // align stack
//     __asm__ volatile("sub $8, %%rsp" ::: "rsp","memory");

//     int ret = Lth_Entry(argc, argv);

//     __asm__ volatile("add $8, %%rsp" ::: "rsp","memory");

//     unsigned long code = (unsigned long)ret;

//     __asm__ volatile(
//         "mov $1, %%rax\n"   // SYS_exit
//         "mov %0, %%rdi\n"
//         "syscall\n"
//         :
//         : "r"(code)
//         : "rax","rdi"
//     );

//     __builtin_unreachable();
// }

void Lth_Start(int argc, char **argv)
{
    int ret = Lth_Entry(argc, (const char **)argv);
    __builtin_trap(); // libc exit
}

#include <sys/syscall.h>
#include <unistd.h>
#include <X11/Xlib.h>

int Lth_Entry(int argc, const char *argv[])
{
    const char *msg = "Hello\n";
    
    XOpenDisplay(NULL);

    return 0;
}

int Convergent(int argc, const char *argv[], ...);

int main(int argc, const char *argv[]) { return Convergent(argc, argv); }