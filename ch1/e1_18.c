#include <stdio.h>

#define MAX_SIZE 1024

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

int is_ws(char c) {
	return c == ' ' || c == '\t';
}

void rtrim(char s[], int len) {
	for (int i = len - 1; i >= 0; i--) {
		if (is_ws(s[i])) {
			s[i] = '\0';
		} else {
			break;
		}
	}
}

int is_blank(char s[]) {
	int i = 0;
	int c;
	while (i < MAX_SIZE && (c = s[i]) != '\0') {
		if (!is_ws(c) && c != '\n') {
			return 0;
		}
		i++;
	}
	return 1;
}

int main(void) {
	char line[MAX_SIZE];
	int len = 0;
	while ((len = get_line(line)) > 0) {
		rtrim(line, len);
		if (!is_blank(line)) {
			printf("%s", line);
		}
	}
	return 0;
}

