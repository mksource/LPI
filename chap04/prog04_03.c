#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tlpi_hdr.h"

#define MAX_READ 1024

int main(int argc,char *argv[])
{

        int outputFd;
        char buffer[MAX_READ];


	if(argc !=2 || strcmp(argv[1],"--help")==0)
          usageErr("%s outputfile",argv[0]);

         outputFd=open(argv[1],O_CREAT | O_WRONLY,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
         if(outputFd==-1)
            errExit("open");
         
         printf("Enter the input:\");
         if(read(STDIN_FILENO,buffer,MAX_READ)==-1)
      
                 


        
         exit(EXIT_SUCCESS);

}
