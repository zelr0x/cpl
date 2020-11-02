#include <stdio.h>

#define MAX_SIZE 1024

int get_line(char s[], int count) {
	int c, i;
	for (i = 0; i < count-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char src[], char dst[], int count) {
	if (count < 1) return;
	int i = 0;
	for (; i < count-1 && src[i] != '\0'; i++) {
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
	while ((len = get_line(line, MAX_SIZE)) > 0) {
		if (len > max_len) {
			max_len = len;
			copy(line, longest, len);
		}
	}
	if (max_len > 0) {
		printf("%s\n", longest);
	}
	return 0;
}

