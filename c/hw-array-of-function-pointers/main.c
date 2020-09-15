#include <stdio.h>

#define ARRAYSIZE(x) (sizeof x/sizeof x[0])

enum response_type {CONGRATULATE, PROMOTE, FIRE};
typedef struct {
    char *name;
    enum response_type type;
} response;

void fire(response r)
{
    printf("Dear %s,\n", r.name);
    puts("We would like to inform you that you are being");
    puts("let go, please pack up your station by the end");
    puts("of the day. Thanks and best wishes.\n");
}

void promote(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Management has reviewed your progress over the");
    puts("last year and would like to offer you a promotion!\n");
}

void congratulate(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Congratulations! You did an amazing job over");
    puts("the last year. Please accept this bonus as");
    puts("a token of our appreciation.\n");
}

void (*replies[])(response) = {fire, promote, congratulate}; // This is an array of function pointers with replies as the
                                                             // variable name. The function pointers return void and take
                                                             // a response for the parameter.

int main()
{
    response r[] = {
        {"Rob", CONGRATULATE},
        {"Elliot", PROMOTE},
        {"Paul", FIRE},
    };

    for (int i = 0; i < ARRAYSIZE(r); i++) {
        (replies[r[i].type])(r[i]); // This is where we are calling the functions and giving the corresponding responses.
    }

    return 0;
}