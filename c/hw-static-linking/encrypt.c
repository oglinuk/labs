#include "encrypt.h"

void encrypt(char *msg)
{
    while (*msg) {
        *msg = *msg ^ 7;
        msg++;
    }
}