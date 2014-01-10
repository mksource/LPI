#include "tlpi_hdr.h"
#include "signal_functions.h"

int main(int argc,char *argv[])
{

	printf("To print the Signal Mask for this process\n");
        printSigMask(stdout,"Signal Mask of this process is");
        exit(0);

}

