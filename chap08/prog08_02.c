#include <grp.h>
#include "tlpi_hdr.h"

int main(int argc,char *argv[])
{

	struct group *grp;

        while((grp=getgrent())!=NULL)
             printf("%-8s %5ld\n",grp->gr_name,grp->gr_passwd);
       
       endgrent(); 


}
