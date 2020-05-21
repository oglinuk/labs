#include <stdio.h>

void say(char thing[]) {
	printf("%s from hw-sizeof!\n", thing);
	printf("The sizeof things pointer is %li bytes ...\n", sizeof(thing));
}

int main() {
	char thing[12] = "Hello world";
	say(thing);
	printf("The sizeof things value is %li bytes ...\n", sizeof(thing));
	printf("The sizeof an int is %li bytes ...\n", sizeof(int));
	printf("The sizeof a char is %li bytes ...\n", sizeof(char));
	printf("The sizeof a float is %li bytes ...\n", sizeof(float));
	printf("The sizeof a double is %li bytes ...\n", sizeof(double));
	printf("The sizeof a short is %li bytes ...\n", sizeof(short));
	printf("The sizeof a short int is %li bytes ...\n", sizeof(short int));
	//printf("The sizeof a short char is %li bytes ...\n", sizeof(short char));
	//printf("The sizeof a short float is %li bytes ...\n", sizeof(short float));
	//printf("The sizeof a short double is %li bytes ...\n", sizeof(short double));
	printf("The sizeof a long is %li bytes ...\n", sizeof(long));
	printf("The sizeof a long int is %li bytes ...\n", sizeof(long int));
	//printf("The sizeof a long char is %li bytes ...\n", sizeof(long char));
	//printf("The sizeof a long float is %li bytes ...\n", sizeof(long float));
	printf("The sizeof a long double is %li bytes ...\n", sizeof(long double));

	return 0;
}
