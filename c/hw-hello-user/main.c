#include <stdio.h>

int main() {
	char name[20];
	printf("Enter your name: ");
	scanf("%19s", name); // %19s only allows 19 characters
	printf("Hello %s from hw-hello-user.c!\n", name);
	return 0;	
}
