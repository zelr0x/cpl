#include <stdio.h>
#include <string.h>

static size_t _itoa(int n, char s[], size_t i) {
    int div = n / 10;
    if (div) {
        i = _itoa(div, s, i);
        s[i++] = n % 10 + '0';
    } else {
        s[i++] = n % 10 + '0';
    }
    return i;
}

/* itoa writes the digits of `n` to `s` from left to right.
   Returns the number of characters in a string, exluding
   the terminating null byte. */
size_t itoa(int n, char s[]) {
    int sign = n; /* record sign */
    size_t i = 0;
    if (sign < 0) {
        n = -n; /* make n positive */
        s[0] = '-';
        i = 1;
    }
    i = _itoa(n, s, i);
    s[i] = '\0';
    return i;
}

int main(void) {
    char buf[50];
    size_t len = itoa(1234567890, buf);
    printf("%s, length=%d\n", buf, len);
}

