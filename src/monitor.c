#include "monitor.h"

int monitor(char* dir, int delay)
{
    struct Monitor monitor;
    memset(monitor.path, 0, DIR_SIZE);
    strncpy(monitor.path, dir, DIR_SIZE - 1);
    // TODO: return error if path was too long

    setup_socket(&monitor);

    setup_stream(&monitor);

    init_directory(&monitor);

    //TODO: should loop forever, only ending on SIGTERM etc? need to handle those properly
    for(int i = 0; i < 10; i++) {
        check_directory(&monitor);

        //TODO: should check continually, only call check_directory with sleep()
        check_socket(&monitor);

        sleep(delay);
    }

    cleanup_stream(&monitor);

    cleanup_socket(&monitor);
}

int setup_socket(struct Monitor *monitor)
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

    //TODO check errors?
    listen(sock, 1); //listen for connections, allow max 1 to be queued

    //sets socket as non-blocking
    int opts = fcntl(sock, F_GETFL);

    if(opts < 0) {
        exit(1);
    }

    opts = (opts | O_NONBLOCK);

    if(fcntl(sock, F_SETFL, opts) < 0) {
        exit(1);
    }

    monitor->socket = sock;
}

int setup_stream(struct Monitor *monitor)
{
    monitor->stream = open_memstream(&(monitor->stream_buf), &(monitor->stream_size));
    // TODO: validity check the memstream
}

int cleanup_socket(struct Monitor *monitor)
{
    close(monitor->socket);
    unlink(SOCKET_PATH);
}

int cleanup_stream(struct Monitor *monitor)
{
    fclose(monitor->stream);
    free(monitor->stream_buf);
}

int check_socket(struct Monitor *monitor)
{
    // TODO: non-blocking check
    int connection = accept(monitor->socket, 0, 0);

    if (connection < 0) {
        //connect error
    } else {
        char read_buf[BUF_SIZE];
        memset(read_buf, 0, BUF_SIZE);

        if (fread(read_buf, 1, BUF_SIZE, monitor->stream) < 0) {
            //stream read error
        }

        if (write(connection, read_buf, BUF_SIZE) < 0) {
            //write error
        } 
        // TODO: how do we handle there being more data to write than BUF_SIZE?
    }

    close(connection);
}
