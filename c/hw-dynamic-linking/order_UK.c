#include <stdio.h>
#include <order.h>

void calc_total(float weight, double price)
{
    float uk_weight = weight / 2.2046;
    printf("Weight: %3.2f kg\n", uk_weight);
    printf("Price: £%3.2f\n", price * uk_weight);
}