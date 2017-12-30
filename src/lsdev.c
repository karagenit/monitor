#include "lsdev.h"

int main(int argc, char *argv[])
{
    // TODO: pass remaining argv to init or read

    if (argc < 2) {
        help();
    }

    if (!strcmp(argv[1], "init")) {
        lsdev_init();
    } else if (!strcmp(argv[1], "read")) {
        lsdev_read();
    } else {
        help();
    }
}

int help()
{
    printf("Usage: lsdev COMMAND\nWhere COMMAND is one of:\n\t'init'\tStart the daemon.\n\t'read'\tPrint the directory changes.");
} 
