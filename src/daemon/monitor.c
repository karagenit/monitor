#include "monitor.h"

int monitor(char* dir, int delay)
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[1024];
    FILE *logfile = NULL;

    logfile = fopen("log.txt", "w+");

    sock = socket(AF_UNIX, SOCK_STREAM, 0);

    // Couldn't open stream socket
    if (sock < 0) {
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, NAME);

    int bind_err = bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    // Couldn't bind stream socket
    if (bind_err) {
        exit(1);
    }

    listen(sock, 5);

    //for (;;) {
    // Will hang until data is written to sock
    msgsock = accept(sock, 0, 0);

    if (msgsock == -1) {
        // Accept error
    } else {
        do {
            // Wipe buffer
            bzero(buf, sizeof(buf));

            // Read bytes into buf, rval is # of bytes read
            rval = read(msgsock, buf, 1024);

            if (rval < 0) {
                // Error reading value
            } else if (rval == 0) {
                // End of Message
            } else {
                // Do something with buf
                fprintf(logfile, buf);
                fflush(logfile);
            }
        } while (rval > 0); // While more bytes to be read
    }
    close(msgsock);
    //}

    close(sock);
    unlink(NAME);

    fclose(logfile);

    //sleep(delay); //eventually this will be used to monitor the directory at intervals
}

int setup_socket()
{
}

int cleanup_socket()
{

}

int check_directory()
{

}

int write_status()
{

}
