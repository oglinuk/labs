/* Simple nuclear meltdown countdown program
 *
 * OGLinuk 2020
 */

#include <stdio.h>
#include <unistd.h>

int main() {
	int count = 7;
	while(count > 0) {
		printf("%i seconds to nuclear meltdown ...\n", count);
		count = count - 1;
		sleep(1); // https://linux.die.net/man/3/sleep
	}
	puts("BOOOOOOM!");
	return 0;
}
