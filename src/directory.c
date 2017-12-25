#include "directory.h"

int init_directory(struct Monitor *monitor)
{
    memset(monitor->dir_list, 0, LIST_SIZE * DIR_SIZE); //todo SIZEOF(char)?

    DIR *directory = opendir(monitor->path);

    if (directory) {
        for(int i = 0; i < LIST_SIZE; i++) {
            struct dirent *entry = readdir(directory);
            if(entry == NULL) {
                break;
            }
            strncpy(monitor->dir_list[i], entry->d_name, DIR_SIZE - 1);
        }
        closedir(directory);
    } else {
        //directory error
    }
}

int check_directory(struct Monitor *monitor)
{
    char found[LIST_SIZE];
    memset(found, 0, LIST_SIZE);

    for (int i = 0; i < LIST_SIZE; i++) {
        if (monitor->dir_list[i]) {
            fprintf(monitor->stream, monitor->dir_list[i]);
            fprintf(monitor->stream, "\n");
        }
    }

    fflush(monitor->stream);

    //grab each directory
    //if it's a new one, add it to dir_list (if possible, 1024 max)
    //and print to stream as +, and mark as "good"
    //if its an existing one, mark as "good"
    //after, print each that aren't marked "good" to stream as -,
    //and drop them from the list

    //weird bug: if there are 1025 items in dir, the last will constantly
    //be seen as a "new" dir (as it can't be stored in the list) - easiest fix
    //is to grow the dir_list with realloc calls (requires significant reworking)
}
