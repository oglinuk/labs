#include <stdio.h>
#include <unistd.h>

void powerup(int* level) {
	*level = *level + 1;
}

int main() {
	int power_level = 8998;
	
	while(power_level < 9000) {
		powerup(&power_level);
		printf("The power level is only %d ...\n", power_level);
		sleep(1);
	}
	puts("ITS OVER 9000!");
	return 0;
}
