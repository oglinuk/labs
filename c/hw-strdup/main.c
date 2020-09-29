#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link {
    char *name;
    int min;
    int max;
    struct link *next;
} link;

void info(link *start)
{
    link *l = start;
    for (; l != NULL; l = l->next) {
        printf("Link: %s Size: %i-%i\n", l->name, l->min, l->max);
    }
}

link* create(char *name, int min, int max)
{
    link *l = malloc(sizeof(link));
    l->name = strdup(name); // strdup works out how long a string is, allocates
                            // enough memory with malloc, then copies each 
                            // character into the new space on the heap. There
                            // wouldn't be a need to use strdup if name was a
                            // string literal since they are stored in a read-only
                            // space of memory.
    l->min = min;
    l->max = max;
    l->next = NULL;
    return l;
}

void release(link *start)
{
    link *c = start;
    link *next = NULL;
    for (; c != NULL; c = next) {
        next = c->next;
        free(c->name); // Need to release the name string created with strdup.
        free(c); // If we released c first then c->name wouldn't be reachable.
    }
}

int main()
{
    link *start = NULL;
    link *c = NULL;
    link *next = NULL;

    char name[42];
    int min = -8;
    int max = -1;

    for (; fgets(name, 42, stdin) != NULL; c = next) {
        name[strlen(name)-1] = '\0';
        next = create(name, (min += 8), (max += 8));
        if (start == NULL) {
            start = next;
        } else {
            c->next = next;
        }
    }

    info(start);
    release(start);
    return 0;
}