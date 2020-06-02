#include <stdio.h>
#include <unistd.h>

int main()
{
	int count = 7;
	while(count > 0) {
		printf("%i seconds to nuclear meltdown ...\n", count);
		count -= 1;
		sleep(1); // man sleep
	}
	puts("BOOOOOOM!");
	return 0;
}
