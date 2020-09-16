#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    if (execl("/usr/games/chocolate-doom", "/usr/games/chocolate-doom", "-iwad", "DOOM.WAD", NULL) == -1) {
        fprintf(stderr, "Failed to find chocolate-doom: %s\n", strerror(errno)); // The errno is an integer of
                                                                                 // the last error. The strerror
                                                                                 // is a function that returns
                                                                                 // a string describing the 
                                                                                 // error number of errno.
        return 1;
    }

    return 0;
}