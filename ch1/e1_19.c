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

void swap(char s[], int i, int j) {
	char t = s[i];
	s[i] = s[j];
	s[j] = t;
}

void reverse(char s[], int len) {
	for (int i = 0, j = len - 1, mid = len / 2; i != mid; i++, j--) {
		swap(s, i, j);
	}
}

/* 
 * Since it is required to just reverse each string,
 * this program doesn't ignore the first newline,
 * and doesn't add newline at the end of the output.
 */
int main(void) {
	char line[MAX_SIZE];
	int len = 0;
	while ((len = get_line(line)) > 0) {
		reverse(line, len);
		printf("%s", line);
	}
	return 0;
}

