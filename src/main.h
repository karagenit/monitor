/**
 * @file    main.h
 * @author  Caleb Smith
 * @date    29 December 2017
 *
 * The core application responsible for launching init/read routines.
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "read.h"

/**
 * Main entry point of the application.
 */
int main(int argc, char *argv[]);

/**
 * Prints the help menu.
 */
int help();

#endif
