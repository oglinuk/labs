#include <string>
#include <unistd.h>

int main()
{
    // man fork
    fork();
    fork();
    fork();
    printf("Hello world from hw-fork!\n");

    return 0;
}