#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	fork();
	fork();
	puts("Hello world from hw-fork!");
}
