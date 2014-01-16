#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "tlpi_hdr.h"

#define MAX_READ 128

int main(int argc,char *argv[])
{
        int infile;
        int outfile;
        int numRead=0;
        char buffer[MAX_READ];
        char outbuffer[MAX_READ];
        int i=0;
        int len=0;
        int start=0;
        int end=0;

        if(argc != 3 || strcmp(argv[1],"--help")==0)
          usageErr("%s infile outfile",argv[0]);

        infile=open(argv[1],O_RDONLY);
        if(infile==-1)
          errExit("open error");

        outfile=open(argv[1],O_CREAT | O_RDWR | O_APPEND,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
        if(outfile==-1)
          errExit("open error");

        
       while((numRead=read(infile,buffer,MAX_READ))>0){
        
          for(i=0;i<numRead;i++){
              while(buffer[i]=='\0'){
                i++;
                len++;
           }
           if(len>0){
              if(write(outfile,outbuffer,end-start)!=end-start)
                 errExit("write error)");
              start=end;
              lseek(outfile,len,SEEK_CUR);
              len=0;
          }
          outbuffer[i]=buffer[i];
          end=i;

       }



	exit(EXIT_SUCCESS);
}
