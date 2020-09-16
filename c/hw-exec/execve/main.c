#include <stdio.h>
#include <unistd.h>

int main()
{
    char *env_arg[] = {"ARG=from exeve!", NULL};
    char *args[] = {"execve", "hello", "world", NULL};

    // The execve function takes a (v)ector and (e)nvironment variables.
    execve("execve", args, env_arg);
    return 0;
}