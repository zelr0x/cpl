#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(const int x, const int v[], const int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; /* found match */
    }
    return -1; /* no match */
}

int main(void) {
    printf("%d\n", binsearch(5, (int[]) {0, 10, 5, 100, -55}, 5));
    return 0;
}

