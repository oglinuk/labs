#include <unistd.h>

int main() {
    char *argv[] = {
        "ls",
        NULL
    };
    execvp(argv[0], argv);

    return 0;
}