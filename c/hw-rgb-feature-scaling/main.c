#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	if (argc < 2) {
		printf("Usage: ./main <0-255>\n");
		exit(-1);
	}

	char *endptr;
	float n = strtof(argv[1], &endptr);

	float normalized = n / 255.0;

	printf("%0.1f normalized: %0.2f\n", n, normalized);

	return 0;
}
