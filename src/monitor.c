#include "monitor.h"

int monitor(char* dir, int delay)
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[BUF_SIZE];
    FILE *logfile = NULL;

    logfile = fopen("log.txt", "w+");

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);

    // Couldn't open stream socket
    if (sock < 0) {
        fprintf(logfile, "Socket");
        exit(1);
    }

    fprintf(logfile, "Socked!");

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    // binds to the file "socket"
    int bind_err = bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    // Couldn't bind stream socket
    if (bind_err) {
        fprintf(logfile, "Bind");
        exit(1);
    }

    fprintf(logfile, "Bound!");

    ssize_t send_err = sendto(sock, "Hello", sizeof("Hello"), 0, (struct sockaddr *) &server, sizeof(struct sockaddr_un));
    //ssize_t send_err = write(sock, "Hello", sizeof("Hello"));

    if (send_err < 0) {
        fprintf(logfile, "Send");
        exit(1);
    }

    fprintf(logfile, "Sent!");

    sleep(30); //I don't know if we are able to close it right away before the data is read or not...

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
