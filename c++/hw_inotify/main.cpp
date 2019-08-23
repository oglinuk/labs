#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#define MAX_EVENT 2048
#define NAME_LEN 32
#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN MAX_EVENT*(EVENT_SIZE+NAME_LEN)

int main(int argc, char const *argv[]) {
    int fd, wd, i, length;
    char buffer[BUF_LEN];

    if(argc < 2) {
        printf("Usage: ./main <dir/file> ...\n");
        return -1;
    }

    fd = inotify_init();
    if(fd < 0) {
        perror("inotify_init");
    }

    wd = inotify_add_watch(fd, argv[1],
                            IN_MODIFY | IN_CREATE | IN_DELETE);

    if(wd == -1) {
        perror("wd");
    } else {
        printf("Starting watch on %s ...\n", argv[1]);
    }


    while(1) {   
        i = 0;
        
        length = read(fd, buffer, BUF_LEN);
        if(length < 0) {
            perror("read");
        }

        while(i < length) {
            struct inotify_event *event = (struct inotify_event *) &buffer[i];
            if(event->len) {
                if(event->mask & IN_CREATE) {
                    if(event->mask & IN_ISDIR) {
                        printf("The directory %s was created ...\n", event->name);
                    } else {
                        printf("The file %s was created ...\n", event->name);
                    }
                }
                if(event->mask & IN_DELETE) {
                    if(event->mask & IN_ISDIR) {
                        printf("The directory %s was deleted ...\n", event->name);
                    } else {
                        printf("The file %s was deleted ...\n", event->name);
                    }
                }
                if(event->mask & IN_MODIFY) {
                    if(event->mask & IN_ISDIR) {
                        printf("The directory %s was modified ...\n", event->name);
                    } else {
                        printf("The file %s was modified ...\n", event->name);
                    }
                }
            }
            i += EVENT_SIZE + event->len;
        }
    }
    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;
}