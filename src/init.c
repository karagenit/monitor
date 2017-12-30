#include "init.h"

// TODO: take args for dir & delay?
int lsdev_init()
{
    pid_t process_id = 0;
    pid_t sid = 0;

    process_id = fork();

    if (process_id < 0)
    {
        printf("Failed to Fork Process!\n");
        exit(1);
    }

    // We are the parent process, so we'll quit now
    if (process_id > 0)
    {
        printf("Created Child Daemon with PID %d\n", process_id);
        exit(0);
    }

    //unmask the file mode
    umask(0);
    //chdir("/"); 
    // TODO: set dir to the directory to be watched?

    sid = setsid();
    if(sid < 0)
    {
        exit(1);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    sleep(1);

    // Run main daemon process
    monitor("./test", 1);
}
