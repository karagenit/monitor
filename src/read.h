/**
 * @file read.h
 * @author  Caleb Smith
 * @date    23 December 2017
 *
 * This file responsible for connecting to the watchdog
 * daemon's socket and reading directory changes.
 */

#ifndef READ_H
#define READ_H

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"

/**
 * Reads from the socket connection for filesystem changes.
 * @param dir   The directory to check for changes on.
 */
int monitor_read(char *dir);

#endif
