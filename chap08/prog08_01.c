#include "tlpi_hdr.h"
#include <pwd.h>

int main(int argc,char *argv[])
{

	struct passwd *pwd;

        while((pwd=getpwent())!=NULL)
             printf("%-8s %-8s %5ld  %5ld %-8s %-8s %-8s\n ",pwd->pw_name,pwd->pw_passwd,(long)pwd->pw_uid,(long)pwd->pw_gid,pwd->pw_gecos,pwd->pw_dir,pwd->pw_shell);

       endpwent(); 

}
