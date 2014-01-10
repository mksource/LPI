#ifdef SIGNAL_FUNCTIONS
#define SIGNAL_FUNCTIONS

void printSigset(FILE *of,const char *prefix,const sigset_t *sigset);
int printSigMask(FILE *of,const char *msg);
int printPendingSigs(FILE *of,const char *msg);

#endif
