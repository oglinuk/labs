#include <stdio.h>

// Linked-list. If you want to read an element at the ith index
// you would have to read all the way up to the ith index. Use
// a linked-list when you want to insert things quickly, but if
// you want direct access to an element use an array.
typedef struct link {
    char *name;
    int min;
    int max;
    struct link *next;
} link;

void info(link *start)
{
    link *l = start;
    for (; l != NULL; l = l->next) { // Note the ; at the start of the for loop
        printf("Link: %s Size: %i-%i\n", l->name, l->min, l->max);
    }
}

int main()
{
    link chain0 = {"chain 0", 0, 7, NULL};
    link chain1 = {"chain 1", 8, 15, NULL};
    link chain2 = {"chain 2", 23, 31, NULL};
    link chain3 = {"chain 3", 39, 47, NULL};

    chain0.next = &chain1;
    chain1.next = &chain2;
    chain2.next = &chain3;

    link chain4 = {"chain 4", 55, 63, NULL};
    
    chain2.next = &chain4;
    chain4.next = &chain3;

    info(&chain0);
    return 0;
}