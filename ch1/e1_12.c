#include <stdio.h>
#include <stdbool.h>

bool is_ws(char c) {
	return c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r';
}

int main(void) {
	int c;
	bool put_nl = false;
	while ((c = getchar()) != EOF) {
		if (is_ws(c)) {
			if (!put_nl) {
				putchar('\n');
				put_nl = true;
			}
		} else {
			putchar(c);
			put_nl = false;
		}
	}

	return 0;
}
	
