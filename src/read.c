#include "read.h"

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_un server;
    char buf[BUF_SIZE];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    int connect_err = connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    if (connect_err < 0) {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }

    bzero(buf, BUF_SIZE);
    int bytes_read = read(sock, buf, BUF_SIZE);

    if (bytes_read < 0) {
        perror("reading from socket");
    } else if (bytes_read > 0) {
        printf(buf);
    }

    close(sock);
}

