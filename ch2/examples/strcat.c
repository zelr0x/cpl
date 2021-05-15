#include <stdio.h>
#include <stdlib.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], const char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}

int main(void) {
    char a[9] = {'a', 'a', 'a', 'a', '\0', '\0', '\0', '\0', 'g'};
    char b[] = "bbbb";
    strcat(a, b);
    printf("%s\n", a);
    return 0;
}

