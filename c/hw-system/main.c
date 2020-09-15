#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cmd[42];
    printf("Type a bash command: ");
    fgets(cmd, 42, stdin);
    cmd[strlen(cmd)-1] = '\0';

    // This is dangerous, because the user can execute any piece of code.
    system(cmd);
    return 0;
}