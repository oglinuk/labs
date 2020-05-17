/* Simple infinitely looping program
 *
 * OGLinuk 2020
 */

#include <stdio.h>
#include <unistd.h>

int main() {
	int count;
	while(1) {
		printf("In the space of infinity, I am up to %i\n", count);
		count++;
		sleep(1);
	}
	return 0;
}
