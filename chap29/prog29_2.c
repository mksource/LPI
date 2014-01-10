#include <pthread.h>
#include "tlpi_hdr.h"

static void* threadFunc(void * arg)
{
     char *s=(char*)arg;
     printf("%s",s);
     return NULL;
}
int main(int argc,char *argv[])
{
	pthread_t thr;
        pthread_attr_t attr;
        int s;

        printf("Inside Main()");
	
        s=pthread_attr_init(&attr);
        if(s!=0)
          errExitEN(s,"pthread_atrr_init");

        s=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
        if(s!=0)
           errExitEN(s,"pthread_attr_setdeatchstate");

        s=pthread_create(&thr,&attr,threadFunc,"Hello World\n");
        if(s!=0)
          errExitEN(s,"pthread_create");

        s=pthread_attr_destroy(&attr);
        if(s!=0)
           errExitEN(s,"pthread_attr_destroy");

        pthread_exit(NULL);

}
