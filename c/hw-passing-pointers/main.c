#include <stdio.h>

void ptr_pass_three(char name[2], int* num) {
	++*num;
	printf("Pointer [%s][%p] passed to third and is now %d!\n",
		name, &num, *num);
}

void ptr_pass_two(char name[2], int* num) {
	++*num;
	printf("Pointer [%s][%p] passed to second and is now %d!\n",
		name, &num, *num);
	ptr_pass_three(name, num);
}

void ptr_pass_one(char name[2], int* num) {
	++*num;
	printf("Pointer [%s][%p] passed to first and is now %d!\n",
			name, &num, *num);
	ptr_pass_two(name, num);
}

int main() {
	int a = 0;
	int b = 0;
	ptr_pass_one("a", &a);
	ptr_pass_one("b", &b);
	ptr_pass_two("b", &b);
	ptr_pass_three("b", &b);
	return 0;
}
