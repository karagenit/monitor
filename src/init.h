/**
 * @file    init.h
 * @author  Caleb Smith
 * @date    23 December 2017
 *
 * This code is responsible for launching a daemon which
 * monitors the '/dev/' directory.
 */

#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "monitor.h"

/**
 * Initializes the watchdog daemon, including forking to a child
 * process and calling monitor().
 * @param dir   The directory to watch.
 * @param delay The time to wait between directory checks.
 */
int lsdev_init(char *dir, int delay);

#endif
