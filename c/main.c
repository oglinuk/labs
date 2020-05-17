#include <stdio.h>

int main() {
	int known[] = {1, 2, 3, 4, 5, 6, 7};
	int *unknown = known;
	known[6] = *unknown;
	// Can you guess what the unknown is?
	printf("I know the unknown ... it's %i!\n", known[5]);

	return 0;
}
