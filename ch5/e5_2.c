#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SEP '.'

int getch(void) {
    return getc(stdin);
}
void ungetch(int n) {
    ungetc(n, stdin);
}

/* getint: get next double from input into *pn.
   The number must start with the digit and not separator,
   e.g. .5 is incorrect. Base 10 only. */
int getfloat(double *pn) {
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int prev = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(prev);
            return 0;
        }
    }
    *pn = 0;
    for (int fractp = 0, sepseen = 0; c != EOF; c = getch()) {
        if (!isdigit(c)) {
            if (sepseen || c != SEP) {  // either repeating separator or not a digit
                ungetch(c);   
                *pn *= sign;
                *pn /= fractp;
                break;
            }
            sepseen = 1;
            fractp = 1; /* reset fraction power once at SEP */
            continue;
        }        
        *pn = 10 * *pn + (c - '0');
        fractp *= 10;
    }
    return c;
}


int main(void) {
    double i = EOF;
    getfloat(&i);
    if (i == EOF) { // todo: use epsilon
        printf("[debug] i = EOF\n");
    }
    printf("[debug] i = %f\n", i);
    const size_t sz = 128;
    char buf[sz];
    fgets(buf, sz, stdin);
    printf("%s\n", buf);
    return 0;
}
    
