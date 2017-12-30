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

int init_directory(struct Monitor *monitor);
int check_directory(struct Monitor *monitor);
int str_in_arr(int arr_size, int str_size, char str[str_size], char arr[arr_size][str_size]);

#endif
