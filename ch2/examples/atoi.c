#include <stdio.h>
#include <ctype.h>

// Returns true if c is an ascii digit, false otherwise.
int isascdigit(const char c) {
    return c > '0' && c <= '9';
}

int atoi(const char s[]) {
    int n = 0;
    for (int i = 0; isdigit(s[i]); ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }
    printf("%d\n", atoi(argv[1]));
    return 0;
}

