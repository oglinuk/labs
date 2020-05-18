#include <stdio.h>

int main() {
	int num;
	int meaning_of_life = 42;
	printf("Enter a number: ");
	scanf("%i", &num);
	if(num < 1) {
		puts("Please enter a number greater than 0 ...");
		return 1;
	}
	printf("Your number (%i) multiplied by the meaning of life (%i) = %i\n", num, meaning_of_life, (num*meaning_of_life));
	return 0;
}
