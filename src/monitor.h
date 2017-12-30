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
int check_socket(struct Monitor *monitor);

#endif
