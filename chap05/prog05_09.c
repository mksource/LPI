#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{
	int fd1,fd2,fd3;
        char *path="tfile";

        fd1=open(path,O_RDWR | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR);
        fd2=dup(fd1);
        fd3=open(path,O_RDWR);
        write(fd1,"Hello ",6);
        write(fd2,"World ",6);
        lseek(fd2,0,SEEK_SET);
        write(fd1,"HELLO,",6);
        write(fd3,"Gidday",6);
        exit(0);


}
