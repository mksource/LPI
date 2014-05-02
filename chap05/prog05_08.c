#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{

     int fd;
     long num;
     int i=0; 
     
     if(argc < 4 || strcmp(argv[1],"--help")==0)
       usageErr("%s filename num-bytes byte [x]",argv[0]);

      
      if(argc==5){
        fd=open(argv[1],O_RDWR | O_APPEND);
        if(fd==-1)
          errExit("open"); 
      }
      else{
        fd=open(argv[1],O_RDWR);
        if(fd==-1)
          errExit("open");
        if(lseek(fd,0,SEEK_END)<0)
          errExit("lseek");
      }


       num=getLong(argv[2],GN_GT_O,"num-bytes");
       for(i=0;i<num;i++){
          if(write(fd,argv[3],1)!=1)
             errExit("write");
       }

     

      exit(0);
}
