#include "monitor.h"

int monitor(char* dir, int delay)
{
    int server_sock = setup_socket();
    char *stream_buf;
    size_t stream_size;
    FILE *diff_stream = open_memstream(&stream_buf, &stream_size);

    while(1) {
        check_directory(dir);

        fprintf(diff_stream, "hi\n");
        fflush(diff_stream);

        check_socket(server_sock, diff_stream);

        // TODO: don't hang main thread like this, instead check constantly for socket requests
        //sleep(delay);

        break; //temporary
    }

    fclose(diff_stream);
    free(stream_buf);

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

int check_socket(int socket, FILE *stream)
{
    //check socket connection
    // TODO: non-blocking check
    int sock_connection = accept(socket, 0, 0);

    if (sock_connection < 0) {
        //connect error
    } else {
        char stream_data[BUF_SIZE];
        //note this should be the client's BUF_SIZE, as that value
        //is the max that can be read... this can be larger than the # of bytes
        //actually in the stream, as it won't block
        fread(stream_data, 1, sizeof(stream_data), stream); //TODO: check return value
        if (write(sock_connection, stream_data, sizeof(stream_data)) < 0) {
            //write error
        } 
        // TODO: how do we handle there being more data to write than BUF_SIZE?
    }

    close(sock_connection);
}
