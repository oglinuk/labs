#include <string>
#include <unistd.h>

int main() {
    // https://linux.die.net/man/2/fork
    fork();
    fork();
    fork();
    printf("Hello world from hw_fork!\n");

    return 0;
}