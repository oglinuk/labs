#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Arg[1]: %s\nArg[2]: %s\n", argv[1], argv[2]);
    printf("getenv(\"ARG\"): %s\n", getenv("ARG"));
    return 0;
}