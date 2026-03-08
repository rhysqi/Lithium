#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#include <unistd.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/ptrace.h>

bool Check_Debugger()
{
    int mib[4];
    struct kinfo_proc kp;
    size_t len = sizeof(kp);

    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PID;
    mib[3] = getpid();

    if (sysctl(mib, 4, &kp, &len, NULL, 0) == -1)
        return false;

    return (kp.ki_flag & P_TRACED) != 0;
}

int main(int argc, const char *argv[]){
    
    if (Check_Debugger() == true) {
        printf("Debugger detected\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}