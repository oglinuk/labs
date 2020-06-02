#include <stdio.h>
#include <string.h>

#define ARRAYSIZE(x) (sizeof x/sizeof x[0])

char quotes[][666] = {
    "We are insignificant dots in the eyes of infinity.",
    "All those moments will be lost in time, like tears in rain. Time to die.",
    "I fight for the users!",
    "Goddammit, I'd piss on a spark plug if I thought it'd do any good.",
    "What are all the things that brings no one happiness? Life.",
    "Soldiers! In the name of democracy, let us all unite!"
};

void find_quote(char keyword[])
{
    for (int i = 0; i < ARRAYSIZE(quotes); i++)
    {
        if (strstr(quotes[i], keyword))
        {
            printf("Quote: %s\n", quotes[i]);
        } 
    }
}

int main()
{
    char keyword[42];
    printf("Quote keyword: ");
    fgets(keyword, 42, stdin);
    // fgets adds \n to end so need to replace with \0
    keyword[strlen(keyword) - 1] = '\0';
    find_quote(keyword);
    return 0;
}
