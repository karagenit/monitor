/**
 * @file    config.h
 * @author  Caleb Smith
 * @date    23 December 2017
 *
 * This header contains application-specific compile-time configuration values.
 */

#ifndef CONFIG_H
#define CONFIG_H

/**
 * The size of buffers used for sending/receiving data via sockets.
 */
#define BUF_SIZE 1024

/**
 * The max size of each file name
 */
#define DIR_SIZE 32

/**
 * The file name of the socket
 */
#define SOCKET_PATH "socket"

/**
 * The maximum number of file names to track
 */
#define LIST_SIZE 1024

/**
 * Contains all necessary configurations for monitoring
 * a directory, including the in-memory Stream of changes
 * and the socket (output) information.
 */
struct Monitor {
    /**
     * The memory buffer to hold the internal memory stream.
     */
    char *stream_buf;
    /**
     * The size of the in-memory stream.
     * TODO: is this necessary? Isn't it just BUF_SIZE?
     */
    size_t stream_size;
    /**
     * The file pointer to the memory stream.
     */
    FILE *stream;
    /**
     * The file socket connection for writing output to clients.
     */
    int socket;
    /**
     * The list of tracked files in the directory.
     */
    char dir_list[LIST_SIZE][DIR_SIZE];
};

#endif
