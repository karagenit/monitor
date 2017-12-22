#include "read.h"

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_un server, client;
    char buf[BUF_SIZE];

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }

    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCKET_PATH);

    client.sun_family = AF_UNIX;
    strcpy(client.sun_path, "socket-client");

    //is this necessary just for reading, or does this enable multicast stuff?
    int bind_err = bind(sock, (struct sockaddr *) &client, sizeof(struct sockaddr_un));

    int conn_err = connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));

    if (conn_err < 0) {
        perror("connecting socket");
    }

    printf("Reading...\n");

//    socklen_t recv_err = recvfrom(sock, buf, BUF_SIZE, 0, NULL, NULL);
    ssize_t recv_err = read(sock, buf, BUF_SIZE);

    if(recv_err < 0) {
        perror("reading datagram");
    }

    printf(buf);

    close(sock);
}

