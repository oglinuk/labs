// File descriptors are abstract indicators used to access various data streams. File
// descriptors are stored in a descriptor table. Each file descriptor has an associated
// data stream, which are things like a keyboard or a file pointer. The first three
// slots are always the same (stdin (0), stdout (1), stderr (2)). The other slots are
// either empty or connected to a data stream opened by the process. The file descriptor
// table has 0 to 255 slots. You can redirect stdout and stderr on the command line via
// '>' and '2>'.
#include <stdio.h>
#include <unistd.h>

int main()
{                       
    char buf[32];
    snprintf(buf, 32, "/proc/%i/fd", getpid());
    printf("Current process id: %i\n", getpid());
    printf("Executing: 'ls -l %s'\n", buf);
    sleep(3);
    execl("/bin/ls", "ls", "-l", buf, NULL);
    return 0;
}