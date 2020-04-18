/* Simple program to showcase switch statements
 *
 * OGLinuk 2020
 */

#include <stdio.h>

int main() {
	char language = 'c';
	switch(language) {
	case 'g':
		puts("Golang!");
		break;
	case 'r':
		puts("Rust!");
		break;
	case 'c':
		puts("C!");
		break;
	}
	return 0;
}
