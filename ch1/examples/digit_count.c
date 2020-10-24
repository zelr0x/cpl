#include <stdio.h>
#include <stdbool.h>

bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

int char2int(char c) {
	return c - '0';
}

bool is_whitespace(char c) {
	return c == ' ' || c == '\n' || c == '\t';
}

/* count digits, white space, others */
int main(void) {
	int c;
	int ndigit[10] = {0};
	int nwhite = 0, nother = 0;

	while ((c = getchar()) != EOF) {
		if (is_digit(c)) {
			++ndigit[char2int(c)];
		} else if (is_whitespace(c)) {
			++nwhite;
		} else {
			++nother;
		}
	}

	printf("digits =");
	for (int i = 0; i < 10; ++i) {
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}
