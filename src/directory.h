/**
 * @file    directory.h
 * @author  Caleb Smith
 * @date    29 December 2017
 *
 * This file contains the code which actually tracks
 * the target directory's changes, printing new occurances
 * to the output stream.
 */

#ifndef DIRECTORY_H
#define DIRECTORY_H

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
 * Sets the initial state of the directory listing with the files
 * in the directory when the daemon is launched.
 */
int init_directory(struct Monitor *monitor);

/**
 * Checks the directory for changes, updating the list and the output
 * streams accordingly.
 */
int check_directory(struct Monitor *monitor);

/**
 * Adds a string to an array of strings.
 */
int add_str_to_arr(int arr_size, int str_size, char *str, char arr[arr_size][str_size]);

/**
 * Checks if a string exists in an array of strings.
 */
int str_in_arr(int arr_size, int str_size, char *str, char arr[arr_size][str_size]);

#endif
