#include <stdio.h>
#include <stdlib.h>

typedef struct link {
    char *name;
    int min;
    int max;
    struct link *next;
} link;

int main()
{
    link *chain = malloc(sizeof(link)); // Create enough space for a link struct and store the memory address in chain.
    printf("Link memory address: %p\nLink memory size: %li\n", chain, sizeof(link));
    free(chain); // Release the memory allocated from heap address chain.
    return 0;
}