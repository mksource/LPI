#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{
    int fd;

    fd=open(argv[1],O_WRONLY);
    if(fd!=-1){
      printf("[PID %ld] File %s alread exists\n",(long)getpid(),argv[1]);
      close(fd);
    }else if(errno!=ENOENT){
       errExit("open");
    }
    else{
        printf("[PID %ld] File does not exist yet %s\n",(long)getpid(),argv[1]);
        if(argc>2){
          sleep(10);
          printf("[PID %ld] Done Sleeping\n",(long)getpid());
         }  
 
         fd=open(argv[1],O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR);
         if(fd==-1)
           errExit("open");

         printf("[PID %ld] Created file %s exclusively\n",(long)getpid(),argv[1]);

      
    } 
        
    exit(EXIT_SUCCESS);
}

