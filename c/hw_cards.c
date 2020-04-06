/* Simple program to showcase atoi
 *
 * OGLinuk 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
	char card[2];
	printf("Enter a card name: ");
	scanf("%2s", card);
	int cards_value;
	if(strlen(card) < 2) {
		if(tolower(card[0]) == 'k' || tolower(card[0]) == 'q' || tolower(card[0]) == 'j') {
			cards_value = 10;
		} else if(tolower(card[0]) == 'a') {
			cards_value = 11;
		} else {
			printf("You really think %s is a valid card?\n", card);
			return 1;
		}
	} else {
		cards_value = atoi(card);
		if(cards_value < 2 || cards_value > 10) {
			printf("We both know %i is not a valid card ...\n", cards_value);
			return 1;
		}
	}
	printf("The cards value is %i!\n", cards_value);
	return 0;
}
