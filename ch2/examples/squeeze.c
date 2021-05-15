#include <stdio.h>

/* squeeze: delete all c from s */
void squeeze(char s[], const int c) {
    int j;
    for (int i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main(const int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s string char", argv[0]);
        return 1;
    }
    
    char *str = argv[1];
    squeeze(str, argv[2][0]);
    printf("%s\n", str);
    return 0;
}

