#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"echo", "hello", "world", "from", "execv!", NULL};
    
    // The execv function takes a (v)ector.
    execv("/bin/echo", args);
    return 0;
}