#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 127
#define HIST_MAIN_CHAR '|'

bool is_whitespace(char c) {
	return c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r';
}

void print_hist_line(int length) {
	for (int i = 0; i < length; i++) {
		putchar(HIST_MAIN_CHAR);
	}
	putchar('\n');
}

void print_hist(int lengths[], int from, int amount, bool skip_empty) {
	for (int i = from, bound = from + amount; i < bound; i++) {
		int amount = lengths[i];
		if (skip_empty && amount == 0) continue;

		printf("%2d ", i);
		print_hist_line(amount);
	}
}

int main(void) {
	int c;
	int lengths[MAX_WORD_LENGTH + 1] = {0}; // skip 0 length words
	int cur_len = 0;
	while ((c = getchar()) != EOF) {
		if (is_whitespace(c)) {
			if (cur_len <= MAX_WORD_LENGTH) {
				++lengths[cur_len];
			}
			cur_len = 0;
		} else {
			++cur_len;
		}
	}
 
	print_hist(lengths, 1, MAX_WORD_LENGTH, true);
	return 0;
}

