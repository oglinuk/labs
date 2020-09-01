#include <stdio.h>

// A union will use memory for just one of the fields in its definition.
// The largest field will be the amount of space taken up by the union.
// In the example below the quantity union will take up 4 bytes because
// of the float fields (weight and volume).
typedef union {
    short count;    // of pineapples
    float weight;   // of blueberries
    float volume;   // of quava juice
} quantity;

typedef struct {
    const char *name;
    quantity amount;
} order;

int main()
{
    order pineapples = {"pineapples", .amount.count=7}; // This is an example of using designated initializer,
                                                        // which sets a union field value by name (.amount.count).
    order blueberries = {"blueberries", .amount.weight=1.01};
    order quava_juice = {"quava juice", .amount.volume=4.2};

    printf("Order 0: %i %s\n", pineapples.amount.count, pineapples.name);
    printf("Order 1: %2.2f lbs of %s\n", blueberries.amount.weight, blueberries.name);
    printf("Order 2: %2.2f litres of %s\n", quava_juice.amount.volume, quava_juice.name);
}