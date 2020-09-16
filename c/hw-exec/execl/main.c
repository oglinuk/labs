#include <stdio.h>
#include <unistd.h>

int main()
{
    // The execl function takes a (l)ist.
    execl("/bin/echo", "/bin/echo", "hello", "world", "from", "execl!", NULL);
    return 0;
}