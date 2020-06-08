#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *FILE_NAME = "word_list.txt";

int get_line_count()
{
	FILE *f;
	char c;

	f = fopen(FILE_NAME, "r");
	if (f == NULL) {
		fprintf(stderr, "main.c::get_line_count::%s::NULL ...\n", FILE_NAME);
		return 1;
	}

	int line_count = 0;
	while (c = getc(f)) {
		if (c == EOF) {
			break;
		} else if (c == '\n') {
			line_count++;
		}
	}
	fclose(f);
	return line_count;
}

char* get_rand_word(int total_lines)
{
	FILE *f;
	char *line;
	size_t len = 0;
	ssize_t read;
	int current_line = 0;

	f = fopen(FILE_NAME, "r");
	if (f == NULL) {
		fprintf(stderr, "main.c::get_rand_word::%s::NULL ...\n", FILE_NAME);
	}

	srand(time(NULL));
	int rand_line = rand() % total_lines;
	while ((read = getline(&line, &len, f)) != -1) {
		current_line++;
		if (current_line == rand_line) {
			break;
		}
	}

	fclose(f);
	return line;
}

int main()
{
	int total_lines = get_line_count();
	int timer = time(NULL) + 10;
	int total = 0;
	int total_correct = 0;
	char typed[15];

	while (1) {
		total++;
		char *word = get_rand_word(total_lines);

		// TODO: Figure out a way to format better
		printf("%s ", word);
		scanf("%10s", typed);

		if (strcmp(typed, word)) {
			total_correct++;
		}
		if (time(NULL) >= timer) {
			break;
		}
	}
	printf("Times up! You scored %d out of %d!\n", total_correct, total);
	return 0;	
}
