#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place.
   Uses only pointer arithmetic. */
static void reverse(char *s) {
    char *headp = s;
    char *tailp = s;
    while (*tailp++)
        ;
    tailp--; // after iteration it's one behind end
    tailp--; // end must be \0 and we don't want it at the beginning of the result
    while (headp < tailp) {
        int c = *headp;
        *headp = *tailp;
        *tailp = c;
        headp++;
        tailp--;
    }
}

void itoa(int n, char *s) {
    char *scpy = s;
    int sign = 0;
    if ((sign = n) < 0) /* record sign */
        n = -n;
    /* make n positive */
    int i = 0;
    do {
        /* generate digits in reverse order */
        *s++ = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse(scpy);
}

int main(void) {
    char buf[11];
    itoa(1234567890, buf);
    printf("%s\n", buf);
}

