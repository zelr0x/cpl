#include <stdio.h>
#include <stdbool.h>

bool is_whitespace(char c) {
	return c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r';
}

int main(void) {
	int c;
    bool prev_is_whitespace = false;
	while ((c = getchar()) != EOF) {
		if (is_whitespace(c)) {
			if (!prev_is_whitespace) {
				putchar(' ');
				prev_is_whitespace = true;
			}
		} else {
			putchar(c);
			prev_is_whitespace = false;
		}
	}

	return 0;
}

