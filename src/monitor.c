#include "monitor.h"

int monitor(char* dir, int delay)
{
    int server_sock = setup_socket();

    while(1) {
        check_directory(dir);
        check_socket(server_sock);

        // TODO: don't hang main thread like this, instead check constantly for socket requests
        //sleep(delay);

        break; //temporary
    }

    cleanup_socket(server_sock);
}

int setup_socket()
{
    int sock = socket(AF_UNIX, SOCK_STREAM, 0); //Create unix socket, type stream, no params

    if (sock < 0) {
        exit(1);
    }

    struct sockaddr_un sock_addr;
    sock_addr.sun_family = AF_UNIX;
    strcpy(sock_addr.sun_path, SOCKET_PATH);

    if (bind(sock, (struct sockaddr *) &sock_addr, sizeof(struct sockaddr_un)) < 0) {
        exit(1);
    }

    listen(sock, 1); //listen for connections, allow max 1 to be queued

    return sock;
}

int cleanup_socket(int socket)
{
    close(socket);
    unlink(SOCKET_PATH);
}

int check_directory(char *dir)
{

}

int check_socket(int socket)
{
    //check socket connection
    // TODO: non-blocking check
    int sock_connection = accept(socket, 0, 0);

    if (sock_connection < 0) {
        //connect error
    } else {
        if (write(sock_connection, "hi", sizeof("hi")) < 0) {
            //write error
        }
    }

    close(sock_connection);
}
