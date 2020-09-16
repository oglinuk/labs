#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYSIZE(x) (sizeof x/sizeof x[0])

int compare_scores(const void* a, const void* b) // A void* can store a pointer to anything
{
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return int_a - int_b;
}

int compare_scores_desc(const void* a, const void* b)
{
    return compare_scores(b, a);
}

int compare_names(const void* a, const void* b)
{
    char** sa = (char**)a;
    char** sb = (char**)b;
    return strcmp(*sa, *sb);
}

int compare_names_desc(const void* a, const void* b)
{
    return compare_names(b, a);
}

int main()
{
    int i;

    int scores[] = {1729, 42, 65536, 666, 7, 16777216, 101};
    int score_size = ARRAYSIZE(scores);

    qsort(scores, score_size, sizeof(int), compare_scores); // The qsort function modifies the original array.
    puts("The scores in order:");
    for (i = 0; i < score_size; i++) {
        printf("Score = %i\n", scores[i]);
    }

    char *names[] = {"Elliot", "Rob", "Paul", "Ken", "Alice", "Bob"};
    int names_size = ARRAYSIZE(names);

    qsort(names, names_size, sizeof(char*), compare_names_desc);
    puts("\nThe names in order:");
    for (i = 0; i < names_size; i++) {
        printf("%s\n", names[i]);
    }
}
