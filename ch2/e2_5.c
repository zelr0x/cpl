#include <stdio.h>


int contains(const char s[], const char c) {
    if (!s) return 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}

/** 
 * any: returns the first location in a string s1 where any
 *      character from the string s2 occurs, or -1 if s1
 *      contains no characters from s2.
 */
int any(const char s1[], const char s2[]) {
    if (!s1 || !s2) return -1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (contains(s2, s1[i])) return i;
    }
    return -1;
}

int main(const int argc, const char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s s1 s2", argv[0]);
        return 1;
    }
    
    printf("%d\n", any(argv[1], argv[2]));
    return 0;
}

