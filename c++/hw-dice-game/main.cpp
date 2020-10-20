#include <iostream>

int roll()
{
    return rand() % 42;
}

int main()
{
    srand(time(NULL));
    int user_roll = roll();
    int programs_roll = roll();

    if (user_roll > programs_roll) {
        printf("Your roll (%d) is higher than the programs (%d)! You won!\n", user_roll, programs_roll);
    } else {
        printf("Your roll (%d) is not higher than the programs (%d)! You lost!\n", user_roll, programs_roll);     
    }
    return 0;
}