#include <stdio.h>

void int_arithmetic() {
	int numbers[] = {3, 5, 7, 9};
	printf("Numbers array is located at %p\n", numbers);
	printf("Numbers + 2 is located at %p (8 bytes away)\n", numbers + 2);
}

void char_arithmetic() {
	char *msg = "Never, call for backup!";
	puts(msg + 7);
}

int main() {
	char_arithmetic();
	int_arithmetic();
	return 0;	
}
