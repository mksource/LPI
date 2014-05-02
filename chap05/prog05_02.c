#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{
        int inputFd;
        int accessMode;
        int flags;
 
        if(argc !=2 || strcmp(argv[1],"--help")==0)
          usageErr("%s infile",argv[0]);

        inputFd=open(argv[1],O_RDWR);
        if(inputFd==-1)
          errExit("open error");

        flags=fcntl(inputFd,F_GETFL);
        if(flags==-1)
          errExit("fcntl");

        accessMode=flags & O_ACCMODE;
        if(accessMode == O_RDONLY)
            printf("file is Readable only");
        else if(accessMode == O_WRONLY)
            printf("file is Writable only");
        else if(accessMode == O_RDWR)
            printf("file is both readable and writable");
        


       exit(EXIT_SUCCESS);
                                
                               

}
