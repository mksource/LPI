#define _GNU_SOURCE
#include <string.h>
#include <signal.h>
#include "tlpi_hdr.h"

static void sigsegHandler(int sig)
{
        int x;
	printf("Caught signal %d (%s)\n",sig,strsignal(sig));
        printf("The top of the handler is %10p\n",(void *)&x);
        fflush(NULL);

        _exit(EXIT_FAILURE);

}
static void overflowStack(int callNum)
{
	char a[10000];
 
        printf("Call %4d- top of the stack near %10p\n",callNum,&a[0]);
        overflowStack(callNum+1);
}
int main(int argc,char *argv[])
{
	stack_t sigstack;
        struct sigaction sa;
        int j;

        printf("Top of the standard stack is near %10p\n",(void *)&j);

	sigstack.ss_sp=malloc(SIGSTKSZ);
        if(sigstack.ss_sp==NULL)
          errExit("malloc");
	
        sigstack.ss_size=SIGSTKSZ;
        sigstack.ss_flags=0;
        if(sigaltstack(&sigstack,NULL)==-1)
          errExit("sigaltstack");
        printf("Alternative Signal Stack is at %10p-%p\n",sigstack.ss_sp,(char *)sbrk(0)-1);
        sa.sa_handler=sigsegHandler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags=SA_ONSTACK;
        if(sigaction(SIGSEGV,&sa,NULL)==-1)
          errExit("sigaction");  

        overflowStack(1);
} 
