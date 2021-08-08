#include <stdio.h>

/* printd: print n in decimal */
void printd(register int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

int main(void) {
    printd((-1 << 31) + 1);
    putchar('\n');

    return 0;
}
    
