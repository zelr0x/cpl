#include <stdio.h>

/* strncmp: return <0 if s<t, 0 if s==t, >0 if s>t.
   Compares only n first bytes. */
int strncmp(char *s, char *t, size_t n) {
    for (; n-- && *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}

int main(void) {
    printf("a, a, 0:\t%d\n", strncmp("a", "a", 0));
    printf("\"\", \"\", 0:\t%d\n", strncmp("", "", 0));
    printf("abc, abc, 2:\t%d\n", strncmp("abc", "abc", 2));
    printf("abc, abc, 3:\t%d\n", strncmp("abc", "abc", 3));
    printf("abc, abc, 4:\t%d\n", strncmp("abc", "abc", 4));
    printf("abc, abcd, 2:\t%d\n", strncmp("abc", "abcd", 2));
    printf("abc, adb, 2:\t%d\n", strncmp("abc", "adb", 2));
    return 0;
}

