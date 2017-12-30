#include "lsdev.h"

int main(int argc, char *argv[])
{
    if (argc == 4 && !strcmp(argv[1], "init")) {
        lsdev_init(argv[2], 1); //TODO: convert argv[3] to int to be passed here
    } else if (argc == 3 && !strcmp(argv[1], "read")) {
        lsdev_read(argv[2]);
    } else {
        help();
    }
}

int help()
{
    printf("Usage: lsdev COMMAND DIRECTORY <DELAY>\n");
    printf("Where COMMAND is one of:\n");
    printf("\t'init'\tStart the daemon.\n");
    printf("\t'read'\tPrint the directory changes.\n");
    printf("Where DIRECTORY is the directory to monitor,\n");
    printf("and where DELAY is the time in between directory checks.\n");
} 
