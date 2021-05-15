#include <stdio.h>

int contains(const char s[], const char c) {
    if (!s) return 0;
    for (int i = 0; s && s[i] != '\0'; i++) {
        if (s[i] == c) return 1;
    }
    return 0;
}

/* squeeze: delete all characters of s2 from s1 */
void squeeze(char s1[], const char s2[]) {
    int j;
    for (int i = j = 0; s1[i] != '\0'; i++) {
        if (!contains(s2, s1[i])) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main(const int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s s1 s2", argv[0]);
        return 1;
    }
    
    char *s1 = argv[1];
    squeeze(s1, argv[2]);
    printf("%s\n", s1);
    return 0;
}

