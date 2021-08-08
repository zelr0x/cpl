#include <stdio.h>

static void _reverse(char s[], size_t n, size_t i) {
    if (i >= n) return;
    char t = s[i];
    n--;
    s[i] = s[n];
    s[n] = t;
    _reverse(s, n, i+1);
}

void reverse(char s[], size_t n) {
    _reverse(s, n, 0);
}
    
int main(void) {
    char even[] = "123456";
    reverse(even, 6);
    printf("%s\n", even);

    char odd[] = "12345";
    reverse(odd, 5);
    printf("%s\n", odd);

    char empty[] = "";
    reverse(empty, 0);
    printf("%s\n", empty);
}

