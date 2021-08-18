#include <stdio.h>
#include <string.h>

/* strend: returns 1 if the string `t` occurs at the end
   of the string `s`, 0 otherwise. */
int strend(char *s, char *t) {
    ssize_t slen = 0;
    ssize_t tlen = 0;
    while (*s++)
        ++slen;
    while (*t++)
        ++tlen;
    if (tlen > slen) return 0;
    while (tlen-->=0) {
        if (*--t != *--s) return 0;
    }
    return 1;
}

int main(void) {
    int good = strend("hello, world", ", world");
    int bad = strend("hello, world", "a world");
    int rlonger = strend("hello", " hello");
    int empty = strend("", "asd");
    printf("good=%d, bad=%d, rlonger=%d, empty=%d\n",
        good, bad, rlonger, empty);
    return 0;
}
   
