#include <stdio.h>

#define MAX_SIZE 1024
#define THRESHOLD 80

int get_line(char s[]) {
	int c, i;
	for (i = 0; i < MAX_SIZE-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main(void) {
	char line[MAX_SIZE];
	int len = 0;
	while ((len = get_line(line)) > 0) {
		if (len > THRESHOLD) {
			printf("%s\n", line);
		}
	}
	return 0;
}

