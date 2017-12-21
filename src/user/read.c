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

    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)) < 0) {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }
    if (write(sock, DATA, sizeof(DATA)) < 0)
        perror("writing on stream socket");
    close(sock);
}

