#include <stdio.h>

void add_numbers(int a, int b)
{
    printf("The sum of %d and %d is %d\n", a, b, a+b);
}

int main()
{
    void (*add_fn) (int, int); // The add_fn is a variable for a function that takes (int, int) and returns void.
    add_fn = add_numbers; // The add_fn variable now stores the address of the add_numbers function.
    add_fn(2, 3);
}