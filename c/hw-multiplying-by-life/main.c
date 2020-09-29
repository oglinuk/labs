#include <stdio.h>

int main()
{
	int num;
	int meaning_of_life = 42;
	printf("Enter a number: ");
	scanf("%i", &num);
	printf("Your number (%i) multiplied by the meaning of life (%i) = %i\n", num, meaning_of_life, (num*meaning_of_life));
	return 0;
}
