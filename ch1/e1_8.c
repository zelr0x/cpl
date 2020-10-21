#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t keep_running = 1;

static void trap(int signal) {
	keep_running = 0;
}

int print_stat(char *name, long count) {
	printf("%s: %ld\n", name, count);
}

int main(void) {
	// looks like sigaction should be used instead of signal
	signal(SIGINT, trap);
	signal(SIGQUIT, trap);

	int c;
	long spaces = 0, tabs = 0, newlines = 0;
	while (keep_running && (c = getchar()) != EOF) {
		if (c == ' ') {
			++spaces;
		} else if (c == '\t') {
			++tabs;
		} else if (c == '\n') {
			++newlines;
		}
	}
	print_stat("Spaces", spaces);
	print_stat("Tabs", tabs);
	print_stat("Newlines", newlines);
	return EXIT_SUCCESS;
}

