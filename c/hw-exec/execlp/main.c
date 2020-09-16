#include <stdio.h>
#include <unistd.h>

int main()
{
    // The execlp function takes a (l)ist of arguments and searches
    // the (P)ATH environment for the program.
    execlp("echo", "echo", "hello", "world", "from", "execlp!", NULL);
    return 0;
}