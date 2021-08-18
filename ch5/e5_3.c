#include <stdio.h>
#include <stdlib.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, const char *t) {
    while (*++s) /* find end of s */
        ;
    while (*s++ = *t++) /* copy t */
        ;
    *s = '\0';
}

int main(void) {
    char a[] = {'a', 'a', 'a', 'a', '\0', '\0', '\0', '\0', 'x'};
    char b[] = "bbbb";
    strcat(a, b);
    printf("%s\n", a);
    return 0;
}

