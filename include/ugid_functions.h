#ifndef UGID
#define UGID
#include "ugid_functions.h"

/*Returns name from corresponfing to 'uid' or NULL on error*/
char *userNameFromId(uid_t uid);

/*Returns UID corresponding to name or error*/
uid_t userIdFromName(const char *name);

/*Returns name corresponing to gid or NULL on error*/
char *groupNameFromId(gid_t gid);

/*Returns GID corresponding to name or -1 on error*/
gid_t groupIdFromName(const char *name);


#endif
