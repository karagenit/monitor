#include "read.h"

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_un server;
    char buf[BUF_SIZE];

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    socklen_t addrlen = sizeof(struct sockaddr_un);

    printf("Reading...\n");

    socklen_t recv_err = recvfrom(sock, buf, BUF_SIZE, 0, (struct sockaddr *) &server, &addrlen);

    if(recv_err < 0) {
        perror("reading datagram");
    }

    printf(buf);

    close(sock);
}

