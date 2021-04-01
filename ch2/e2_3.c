#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

unsigned long htoi(const char* s) {
	return strtoul(s, NULL, 16); // TODO: write by hand
}

int main(void) {
	char* s;
    errno = 0;
    int n = scanf("%m[0-9xXa-fA-F]", &s);
    if (n == 1) {
		printf("%d\n", htoi(s));
        free(s);
    } else if (errno != 0) {
        perror("scanf");
    } else {
        fprintf(stderr, "No matching characters\n");
    }

	return 0;
}

