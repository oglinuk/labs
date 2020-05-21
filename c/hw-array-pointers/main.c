#include <stdio.h>

void indexing() {
	int numbers[] = {1, 3, 5, 7, 9};

	printf("numbers[3] = %i\n", numbers[3]);
	printf("3[numbers] = %i\n", 3[numbers]);
	printf("*(numbers + 3) = %i\n", *(numbers + 3));
	printf("*(3 + numbers) = %i\n", *(3 + numbers));
}

void knowing() {
	int known[] = {3, 5, 9};
	int *unknown = known;

	known[0] = 7;
	known[1] = known[2];
	known[2] = *unknown;

	// What do you think the unknown number will be?
	// Hint: Remember that pointers to arrays point to the address of the
	// first index value of the array
	printf("The unknown number is %i!\n", known[2]);
}

int main() {
	knowing();
	indexing();
	return 0;
}
