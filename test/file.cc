
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){
    
    char mem[8];

    strcpy(mem, argv[1]);

    printf("Mem: %s\n", mem);
    
    return 0;
}