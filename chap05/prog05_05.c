#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{
	int fd;
        char template[]="/tmp/somstringXXXXXX";

        fd=mkstemp(template);
        if(fd==-1)
          errExit("mkstemp");
       printf("Generated filename was %s\n",template);
       unlink(template);

       if(close(fd)==-1)
          errExit("close"); 

      exit(0);
}
