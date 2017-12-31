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
#include <fcntl.h>

#include "config.h"
#include "directory.h"

/**
 * Generates a Monitor config struct and begins
 * monitoring a given filesystem directory for
 * changes.
 * @param delay The time to wait (in seconds) between checks
 */
int monitor(int delay);

/**
 * Sets up the socket connection.
 */
int setup_socket(struct Monitor *monitor);

/**
 * Sets up the internal memory stream for writing output.
 */
int setup_stream(struct Monitor *monitor);

/**
 * Cleans up the internal memory stream.
 */
int cleanup_stream(struct Monitor *monitor);

/**
 * Closes the socket connection.
 */
int cleanup_socket(struct Monitor *monitor);

/**
 * Checks if connections are waiting on the socket.
 * Does not block.
 */
int check_socket(struct Monitor *monitor);

int connect_socket(int connection, struct Monitor *monitor);

#endif
