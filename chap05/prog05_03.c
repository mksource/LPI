#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define STR_SIZE 100

int main(int argc,char *argv[])
{
    int fd;
    struct iovec iov[3];
    struct stat myStruct;
    int x;
    char str[STR_SIZE];
    ssize_t numRead,totRequired;

    if(argc!=2 || strcmp(argv[1],"--help")==0)
      usageErr("%s file\n",argv[0]);

   fd=open(argv[1],O_RDONLY);
   if(fd==-1)
      errExit("open");   

   totRequired=0;

  



}
