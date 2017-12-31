#include "main.h"

int main(int argc, char *argv[])
{
    if (argc == 4 && !strcmp(argv[1], "init")) {
        monitor_init(argv[2], strtol(argv[3], NULL, 10));
    } else if (argc == 3 && !strcmp(argv[1], "read")) {
        monitor_read(argv[2]);
    } else if (argc == 3 && !strcmp(argv[1], "kill")) {
        monitor_kill(argv[2]);
    } else {
        help();
    }
}

int help()
{
    printf("Usage: monitor COMMAND DIRECTORY <DELAY>\n");
    printf("Where COMMAND is one of:\n");
    printf("\t'init'\tStart the daemon.\n");
    printf("\t'read'\tPrint the directory changes.\n");
    printf("Where DIRECTORY is the directory to monitor,\n");
    printf("and where DELAY is the time in between directory checks.\n");
}

int monitor_kill(char *dir)
{
    int sock;
    struct sockaddr_un server;

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

    if (write(sock, "1", sizeof("1")) < 0) {
        perror("writing to socket");
    }

    close(sock);

}
