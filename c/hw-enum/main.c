#include <stdio.h>

// An enum is a list of symbols or names that have an integral constant for its value.
typedef enum {
    COUNT,
    POUNDS,
    PINTS
} unit_of_measure;

typedef union {
    short count;
    float weight;
    float volume;
} quantity;

typedef struct {
    const char *name;
    quantity amount;
    unit_of_measure units;
} order;

void print_order(order o)
{
    if (o.units == PINTS) {
        printf("%2.2f pints of %s\n", o.amount.volume, o.name);
    } else if (o.units == POUNDS) {
        printf("%2.2f lbs of %s\n", o.amount.weight, o.name);
    } else {
        printf("%i %s\n", o.amount.count, o.name);
    }
}

int main()
{
    order pineapples = {"pineapples", .amount.count=7, COUNT};
    order blueberries = {"blueberries", .amount.weight=1.01, POUNDS};
    order quava_juice = {"quava juice", .amount.volume=4.2, PINTS};

    print_order(pineapples);
    print_order(blueberries);
    print_order(quava_juice);
    return 0;
}