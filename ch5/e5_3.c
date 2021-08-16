#include <stdio.h>
#include <stdlib.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char *s, const char *t) {
    while (*++s) /* find end of s */
        ;
    while (*s++ = *t++) /* copy t */
        ;
}

int main(void) {
    char a[10] = {'a', 'a', 'a', 'a', '\0', '\0', '\0', '\0', 'g', '\0'};
    char b[] = "bbbb";
    strcat(a, b);
    printf("%s\n", a);
    return 0;
}

