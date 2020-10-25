#include <stdio.h>
#include <stdbool.h>

#define CHARS 256
#define LABEL_WIDTH 3
#define HIST_MAIN_CHAR '|'

#define FIRST_PRINTABLE_ASCII 33
#define LAST_PRINTABLE_ASCII 126

bool is_printable(int c) {
	return c >= FIRST_PRINTABLE_ASCII && c <= LAST_PRINTABLE_ASCII;
}

void print_label(int c) {
	if (is_printable(c)) {
		printf("%*c ", LABEL_WIDTH, (char) c);
	} else if (c == ' ') {
		printf("%*s ", LABEL_WIDTH, "spc");
	} else if (c == '\n') {
		printf("%*s ", LABEL_WIDTH, "\\n");
	} else if (c == '\t') {
		printf("%*s ", LABEL_WIDTH, "\\t");
	} else {
		printf("%*d ", LABEL_WIDTH, c);
	}
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
		if (amount > 0 || !skip_empty) {
			print_label(i);
			print_hist_line(amount);
		}
	}
}

int main(void) {
	int c;
	int freq[CHARS] = {0};
	while ((c = getchar()) != EOF) {
		if (c >= 0 && c <= CHARS-1) {
			++freq[c];
		}
	}
 
	print_hist(freq, 0, CHARS, true);
	return 0;
}

