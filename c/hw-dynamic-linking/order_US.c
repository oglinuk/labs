#include <stdio.h>
#include <order.h>

void calc_total(float weight, double price)
{
    printf("Weight: %3.2f lbs\n", weight);
    printf("Price: $%3.2f\n", price * weight);
}