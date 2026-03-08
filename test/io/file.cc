#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/sysctl.h>

int main(int argc, const char *argv[]){
    
    // int *x = NULL;

    // printf("%p\n", &x);

    int value;
    size_t len = sizeof(value);

    /* ---- READ CURRENT VALUE ---- */
    if (sysctlbyname("kern.elf64.aslr.enable",
                     &value,
                     &len,
                     NULL,
                     0) == -1)
    {
        perror("sysctlbyname (get)");
        return 1;
    }

    printf("ASLR current value: %d\n", value);

    /* ---- TOGGLE VALUE ---- */
    int new_value = value ? 0 : 1;

    if (sysctlbyname("kern.elf64.aslr.enable",
                     NULL,
                     NULL,
                     &new_value,
                     sizeof(new_value)) == -1)
    {
        perror("sysctlbyname (set)");
        return 1;
    }

    /* ---- READ AGAIN TO CONFIRM ---- */
    len = sizeof(value);
    if (sysctlbyname("kern.elf64.aslr.enable",
                     &value,
                     &len,
                     NULL,
                     0) == -1)
    {
        perror("sysctlbyname (verify)");
        return 1;
    }

    printf("ASLR new value: %d\n", value);
    
    return 0;
}