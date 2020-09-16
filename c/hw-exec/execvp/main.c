#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"echo", "hello", "world", "from", "execvp!", NULL};

    // The execvp takes a (v)ector andsearches the (P)ATH environment variable for the program.
    execvp("echo", args);
    return 0;
}