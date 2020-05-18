#include <stdio.h>

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		puts("Usage: ./main <arg1> <arg2> ...");
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		printf("Arg%d: %s\n", i, argv[i]);
	}

	return 0;
}
