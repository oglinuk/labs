#include <stdio.h>
#include <stdlib.h>

void open(char *url)
{
    char cmd[255];
    sprintf(cmd, "x-www-browser '%s' &", url);
    system(cmd);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        open("https://en.wikipedia.org/wiki/Deep_learning");
    } else {
        open(argv[1]);
    }
    return 0;
}