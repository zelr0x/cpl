#include <stdio.h>
#include <stdlib.h>

/* strncat: concatenate t to end of s */
void strcat(char *s, const char *t, size_t n) {
    while (*++s) /* find end of s */
        ;
    while (n--) /* copy t */
        *s++ = *t++;
    *s = '\0';
}

int main(void) {
    char a[] = {'a', 'a', 'a', '\0', '\0', 'x'}; // need not be null-terminated
    char *b = "bbbb";
    strcat(a, b, 2);
    printf("%s\n", a);
    return 0;
}

