
#include <sys/capsicum.h>
#include <sys/caprights.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc, const char *argv[]){

    int fd;
    char *txt = (char *)"capability.txt";

    fd = open(txt, O_WRONLY | O_CREAT, 0777);
    if (fd < 0) return 1;
    
    cap_rights rights;
    cap_rights_init(&rights, CAP_WRITE);

    if(cap_rights_limit(fd, &rights) < 0) return 2;

    if (cap_enter() < 0) return 3;

    txt = (char *)"capability_1.txt";
    fd = open(txt, O_WRONLY | O_CREAT, 0777);

    if (fd < 0) return printf("Cannot create new file");

    write(fd, (char*)"hello", sizeof("hello") - 1);
    
    return 0;
}