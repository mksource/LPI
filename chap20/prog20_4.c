#include<signal.h>
#include "tlpi_hdr.h"

static void sigHandler(int sig){
	printf("Caught Signal");
}
int main(int argc,char *argv[])
{
      int i;
      printf("In Main");
     
    
     if(signal(SIGINT,sigHandler)==SIG_ERR)
       errExit("signal error");

     
        
     
     raise(SIGINT);
}         
