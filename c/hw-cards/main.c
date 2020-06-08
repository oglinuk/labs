#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char card[3]; // The array size should be 3 not 2 to account for the sentinal character (\0)
	printf("Enter a card name: ");
	scanf("%2s", card);
	int cards_value;
	int card_count;
	if (tolower(card[0]) == 'k' || tolower(card[0]) == 'q' || tolower(card[0]) == 'j') {
		cards_value = 10;
	} else if (tolower(card[0]) == 'a') {
		cards_value = 11;
	} else {
		cards_value = atoi(card);
		if(cards_value < 2 || cards_value > 10) {
			printf("We both know %i is not a valid card ...\n", cards_value);
			return 1;
		}
	}
	
	if ((cards_value > 1) && (cards_value < 7)) {
		puts("Count +1 ...");
	} else if ((cards_value > 9) && (cards_value < 12)) {
		puts("Count -1 ...");
	} else {
		puts("Count hasn't changed ...");
	}
	printf("The cards value is %i!\n", cards_value);
	return 0;
}
