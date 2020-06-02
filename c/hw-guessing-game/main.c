#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int again()
{
	char ans[2];

	printf("Play again? [y/N]: ");
	scanf("%1s", ans);

	if(tolower(ans[0]) == 'y') {
		return 0;
	}

	return 1;
}

int get_guess()
{
	int guess = 0;

	printf("Guess: ");
	scanf("%i", &guess);

	return guess;
}

void new_game()
{
	system("clear");
	srand(time(NULL));
	int rng_num = rand() % 10;
	int guess = -1;
	int guesses = 0;
	while	(guess != rng_num) {
		guess = get_guess();
		guesses++;
		if	(guess > rng_num) {
			puts("Guess was too high!");
		} else if (guess < rng_num) {
			puts("Guess was too low!");
		} else {
			printf("Correct! It took %d guesses ...\n", guesses);
		}
	}
}

int main()
{
	int play = 1;

	do {
		new_game();
		play = again();
	} while(play == 0);

	return 0;
}
