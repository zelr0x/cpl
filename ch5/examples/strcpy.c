void strcpy_arr(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        ;
}

/* strcpy: copy t to s */
void strcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}

