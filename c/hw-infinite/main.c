#include <stdio.h>
#include <unistd.h>

int main()
{
	int count;
	while(1) {
		printf("On the count to infinity, I am up to %i\n", count);
		count++;
		sleep(1);
	}
	return 0;
}
