#include <stdio.h>

#define MAX_SIZE 3

int get_line(char s[]) {
	int c, i;
	int limit = MAX_SIZE - 1;
	for (i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	while (i >= limit && (c = getchar()) != EOF && c != '\0' && c != '\n') i++;
	return i;
}

void copy(char dst[], char src[], int count) {
	if (count < 1) return;
	int i = 0;
	for (; i < count && src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	for (; i < count; i++) {
		dst[i] = '\0';
	}
}

int main(void) {
	char longest[MAX_SIZE];
	char line[MAX_SIZE];
	int max_len = 0;
	int len = 0;
	while ((len = get_line(line)) > 0) {
		if (len > max_len) {
			max_len = len;
			copy(longest, line, MAX_SIZE);
		}
	}
	if (max_len > 0) {
		printf("%s\nLength of max line: %d\n", longest, max_len);
	}
	return 0;
}

