#ifndef MONITOR_H
#define MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

#include "config.h"

struct Monitor {
    char dir[DIR_SIZE];
    char *stream_buf;
    size_t stream_size;
    FILE *stream;
    char read_buf[BUF_SIZE];
    int socket;
};

int monitor(char* dir, int delay);
int setup_socket(struct Monitor *monitor);
int setup_stream(struct Monitor *monitor);
int cleanup_stream(struct Monitor *monitor);
int cleanup_socket(struct Monitor *monitor);
int check_directory(struct Monitor *monitor);
int check_socket(struct Monitor *monitor);

#endif
