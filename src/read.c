#include "read.h"

int monitor_read(char *dir)
{
    int sock;
    struct sockaddr_un server;
    char buf[BUF_SIZE];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }

    chdir(dir);

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    int connect_err = connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    if (connect_err < 0) {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }

    memset(buf, 0, BUF_SIZE);
    int bytes_read = read(sock, buf, BUF_SIZE - 1);

    if (bytes_read < 0) {
        perror("reading from socket");
    } else if (bytes_read > 0) {
        printf(buf);
    }

    // TODO: if more data to be read, read & print that too

    close(sock);
}

