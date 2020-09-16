#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arg_env[] = {"ARG=from execle!", NULL};

    // The execle function takes a (l)ist of args and (e)nvironment variables.
    execle("execle", "execle", "hello", "world", NULL, arg_env);
    return 0;
}