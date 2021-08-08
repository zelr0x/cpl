#include <stdio.h>

static void swap(int[], int, int);

void qsort(int v[], int left, int right) {
    if (left >= right) return ;// do nothing if array contains fewer than two elements
    swap(v, left, (left + right)/2); // move partition elem to v[0]
    int last = left;
    for (int i = left + 1; i <= right; i++) { // partition
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void qsort_all(int v[], size_t sz) {
    qsort(v, 0, sz);
}

int main(void) {
    int a[] = {9, 5, 7, -3, 0, 1000, -1000};
    size_t n = sizeof(a) / sizeof(int);
    qsort_all(a, n);
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(", %d", a[i]);
    }
    printf("\n");
    return 0;
}

static void swap(int v[], register int i, register int j) {
    register int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

