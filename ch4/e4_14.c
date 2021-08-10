#include <stdio.h>

#define swap(t, x, y) {\
    t tmp = (x);\
    x = (y);\
    y = tmp;\
}

int main(void) {
    double pi  = 3.14159;
    double e = 2.71828;
    swap(double, pi, e);
    printf("pi = %.5f, e = %.5f\n", pi, e);
}

