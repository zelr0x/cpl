#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int getch(void) {
    return getc(stdin);
}
void ungetch(int n) {
    ungetc(n, stdin);
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}


int main(void) {
    int i = EOF;
    getint(&i);
    if (i == EOF) {
        printf("[debug] i = EOF\n");
    }
    printf("[debug] i = %d\n", i);
    const size_t sz = 128;
    char buf[sz];
    fgets(buf, sz, stdin);
    printf("%s\n", buf);
    return 0;
}
    
