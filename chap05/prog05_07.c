#include "tlpi_hdr.h"
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{

        int fd;
       
         fd=open("tfile",O_RDWR | O_APPEND);
         if(fd==-1)
           errExit("open");

         if(lseek(fd,0,SEEK_SET)<0)
            errExit("lseek");
       
         if(write(fd,"test",4)!=4)
            errExit("write");


	exit(0);
}
