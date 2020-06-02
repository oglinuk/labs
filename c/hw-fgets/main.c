#include <stdio.h>

/*

Differences between fgets and scanf:
- scanf only limits input if you specify, fgets requires a limit
- fgets can't handle multiple fields or data types other than strings,
  whereas scanf can handle different data types and more than one field
- scanf stops reading a string with %s when it's given a space, whereas
  fgets handles spaces just fine

*/
int main()
{
	char something[7];
	printf("Type something: ");
	fgets(something, 7, stdin);
	printf("You typed: %s\n", something);
	return 0;
}
