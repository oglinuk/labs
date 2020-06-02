// Original source: https://www.lemoda.net/c/recursive-directory/

#include <dirent.h>
#include <cstring>
#include <string>
#include <unistd.h>

bool check(dirent *e)
{
    if(strcmp(e->d_name, "..") != 0 &&
        strcmp(e->d_name, ".") != 0 &&
        e->d_type == DT_DIR) {
            return 1;
        }
    return 0;
}

void list_tree(const char * root)
{
    DIR * d;

    d = opendir(root);

    if(!d) {
        fprintf(stderr, "Cannot open directory '%s': %s\n",
                 root, std::strerror(errno));
        exit(1);
    }
    while(1) {
        struct dirent * entry;

        /* "Readdir" gets subsequent entries from "d". */
        entry = readdir(d);
        if(!entry) {
            break; // No more entries in this dir
        }

        if(entry->d_type & DT_DIR) {
            /* Check that the directory is not "d" or d's parent. */
            if(check(entry)) {
                int path_length;
                char path[PATH_MAX];

                path_length = snprintf(path, PATH_MAX,
                                        "%s/%s", root, entry->d_name);
                printf("%s\n", path);
                if(path_length >= PATH_MAX) {
                    fprintf(stderr, "Path length has got too long.\n");
                    exit(1);
                }
                /* Recursively call "list_dir" with the new path. */
                list_tree(path);
            }
        }
    }
    /* After going through all the entries, close the directory. */
    if(closedir(d)) {
        fprintf(stderr, "Could not close '%s': %s\n",
                 root, strerror(errno));
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    if(argc < 2) {
        printf("Usage: ./main <root path>\n");
        return 1;
    }

    list_tree(argv[1]);
    return 0;
}