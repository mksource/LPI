#include<signal.h>
#include<string.h>
#include "tlpi_hdr.h"
#define _GNU_SOURCE

int main(int argc,char *argv[])
{

     printf("%s\n",strsignal(SIGPIPE));
     printf("%s\n",strsignal(SIGFPE));


}

