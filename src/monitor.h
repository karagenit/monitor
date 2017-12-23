/**
 * @file    monitor.h
 * @author  Caleb Smith
 * @date    23 December 2017
 *
 * This file contains the code necessary for monitoring
 * a target directory for changes.
 */

#ifndef MONITOR_H
#define MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

#include "config.h"

/**
 * Contains all necessary configurations for monitoring
 * a directory, including the in-memory Stream of changes
 * and the socket (output) information.
 */
struct Monitor {
    char path[DIR_SIZE];
    char *stream_buf;
    size_t stream_size;
    FILE *stream;
    DIR *directory;
    int socket;
};

/**
 * This function generates a Monitor config struct and
 * begins monitoring a given filesystem directory for
 * changes.
 * @param dir   The directory to watch
 * @param delay The time to wait (in seconds) between checks
 */
int monitor(char* dir, int delay);
int setup_socket(struct Monitor *monitor);
int setup_stream(struct Monitor *monitor);
int cleanup_stream(struct Monitor *monitor);
int cleanup_socket(struct Monitor *monitor);
int check_directory(struct Monitor *monitor);
int check_socket(struct Monitor *monitor);

#endif
