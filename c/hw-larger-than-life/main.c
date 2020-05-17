/* Simple program to showcase a function other than main
 *
 * OGLinuk 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

_Bool is_larger(int n) {
	if(n > 42) {
		return 1;
	}
	return 0;	
}

int main() {
	srand(time(NULL));
	int number = rand() % 84;
	if(is_larger(number)) {
		printf("%i is larger than life(42)!\n", number);
	} else {
		printf("%i is not larger than life(42)!\n", number);
	}
	return 0;
}
