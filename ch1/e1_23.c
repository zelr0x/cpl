/*
TEST:
cc e1_23.c -Wall && ./a.out < e1_23.c > test.c \
&& cc test.c -Wall -o test && ./test < test.c > test2.c \
&& cc test2.c -Wall -o test2 && ./test2 < test2.c; rm ./test.c; rm ./test2.c
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1024

int prev = -1;
int cur = -1;

// Reads line till MAXLINE or the end of multiline comment (EOC), i.e.
// `*/` sequence or `\n` or EOF (since reads only one line).
// Returns true if multiline comment ending or EOF was read.
bool skip_read_line_till_eoc_multiline() {
	extern int prev;
	extern int cur;
	for (int i = 0; i < MAXLINE - 1 
			&& (prev = cur) && (cur = getchar()) != EOF 
			&& cur != '\n'; ++i) {
		if (prev == '*' && cur ==  '/') {
			prev = -1;
			return true;
		}
	}
	return cur == EOF;
}

void skip_read_line() {
	extern /* test*/ int cur;
	for (int i = 0; i < MAXLINE - 1 
			&& (cur = getchar()) != EOF 
			&& cur != '\n'; ++i)
		;
	prev = -1;
}

/*
test
* kek
*/
int main(void) {
	//char devnull[MAXLINE];
	extern int cur;
	extern int prev;
	bool in_str = false;
	bool in_char = false;
	prev = -1;
	while ((cur = getchar()) != EOF) {
		if (!in_str && prev == '/' && cur == '*') {
			while (!skip_read_line_till_eoc_multiline())
				;
			if (cur == EOF) break;
			continue;
		} else if (!in_str && prev == '/' && cur == '/') {
			skip_read_line();
			continue;
		} else if (in_str && cur == '"' && prev != '\\') {
			in_str = false;
		} else if (in_char && cur == '\'' && prev != '\\') {
			in_char = false;
		} else if (!in_str && !in_char) {
			if (cur == '"') in_str = true;
			if (cur == '\'') in_char = true;
		}
		if (prev != -1) {
			putchar(prev);
		}
		prev = cur;
	}
	putchar(prev);
	return 0;
}
/*
FIXME - why does this not removed?
*/
