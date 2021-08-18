#include <stdio.h>

/* strncpy: copy t to s */
void strncpy(char *s, const char *t, size_t n) {
    while (n--) {
        *s++ = *t++;
    }
}

int main(void) {
    char *dest[16];
    char *src = "hello, strncpy";
    strncpy(dest, src, 10);
    printf("whole string: %s\n", src);
    printf("n=10, should end in str: %s\n", dest);
    return 0;
}    

