#include "monitor.h"

int monitor(char* dir, int delay)
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[BUF_SIZE];
    FILE *logfile = NULL;

    logfile = fopen("log.txt", "w+");

    sock = socket(AF_UNIX, SOCK_STREAM, 0);

    // Couldn't open stream socket
    if (sock < 0) {
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    // binds to the file "socket"
    int bind_err = bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    // Couldn't bind stream socket
    if (bind_err) {
        exit(1);
    }

    listen(sock, 5);

    //for (;;) {
    // Will hang until a connection is requested
    msgsock = accept(sock, 0, 0);

    if (msgsock == -1) {
        // Accept error
    } else {
        int write_err = write(msgsock, "Hi", sizeof("Hi"));

        if(write_err < 0) {
            //write failed
        }
    }
    close(msgsock);
    //}

    close(sock);
    unlink(SOCKET_PATH);

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
