#include "directory.h"

int init_directory(struct Monitor *monitor)
{
    memset(monitor->dir_list, 0, LIST_SIZE * DIR_SIZE); //todo SIZEOF(char)?

    DIR *directory = opendir(monitor->path);

    if (!directory) {
        return -1;
    }

    for(int i = 0; i < LIST_SIZE; i++) {
        struct dirent *entry = readdir(directory);
        if(entry == NULL) {
            break;
        }
        strncpy(monitor->dir_list[i], entry->d_name, DIR_SIZE - 1);
    }

    closedir(directory);
}

int check_directory(struct Monitor *monitor)
{
    char found[LIST_SIZE];
    memset(found, 0, LIST_SIZE);

    DIR *directory = opendir(monitor->path);

    if (!directory) {
        return -1;
    }

    while (1) {
        struct dirent *entry = readdir(directory);

        if (entry == NULL) {
            break;
        }

        if (str_in_arr(LIST_SIZE, DIR_SIZE, entry->d_name, monitor->dir_list)) {
            //mark good
        } else {
            //add listing
            //print stream +
            fprintf(monitor->stream, "+");
            fprintf(monitor->stream, entry->d_name);
            fprintf(monitor->stream, "\n");
            //mark good
        }
    }

    for (int i = 0; i < LIST_SIZE; i++) {
        //if not good
        //print stream -
        //remove from list
    }

    fflush(monitor->stream);

    //weird bug: if there are 1025 items in dir, the last will constantly
    //be seen as a "new" dir (as it can't be stored in the list) - easiest fix
    //is to grow the dir_list with realloc calls (requires significant reworking)
}

/*
 * Not sure if entry->d_name will always be null-terminated, but we have to hope...
 * We know each string in arr[] will be null terminated, but we limit the comparison
 * to str_size anyways to be safe.
 */
int str_in_arr(int arr_size, int str_size, char *str, char arr[arr_size][str_size])
{
    for (int i = 0; i < arr_size; i++) {
        if (!strncmp(str, arr[i], str_size)) {
            return 1;
        }
    }
    return 0;
}
