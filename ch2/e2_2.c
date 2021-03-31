#include <stdio.h>

int main(void) {
	const int lim = 100;
	
	int i, c;
	char s[lim];
	for (i = 0; i < lim - 1; ++i) {
		c = getchar();
		if (c != '\n') {
			if (c != EOF) {
				s[i] = c;
			}
		}
	}

	return 0;
}

