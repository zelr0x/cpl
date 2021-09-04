//cc e5_14.c && ./a.out -rn < sortdata.txt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000       /* max #lines to be sorted */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsortkr(void *lineptr[], int left, int right,
             int (*comp)(void *, void *));
static int numcmp(const char *, const char *);
static int rnumcmp(const char *, const char *);
static int rstrcmp(const char*, const char*);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int reverse = 0;    /* 1 if reverse order sort */
    int c;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            }
        }
    }
    // printf("[DEBUG] :: numeric=%d, reverse=%d\n", numeric, reverse);
    void *comp  = strcmp;
    if (numeric && reverse) {
        comp = rnumcmp;
    } else if (numeric) {
        comp = numcmp;
    } else if (reverse) {
        comp = rstrcmp;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsortkr((void**) lineptr, 0, nlines-1,
            (int (*)(void*,void*)) comp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too be to sort\n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
char *alloc(int);

/* getline: read a line, return length */
static size_t getlinekr(char *line, int max) {
    if (fgets(line, max, stdin) == NULL) {
        return 0;
    } else {
        return strlen(line);
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    size_t maxlen = MAXLEN;
    ssize_t len;
    int nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getlinekr(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

/* qsort: K&R qsort; sort v[left]...v[right] into increasing order */
void qsortkr(void *v[], int left, int right,
             int (*comp)(void *, void *)) {
    void swap(void *v[], int i, int j);
    if (left >= right) {    /* do nothing if array contains */
        return;             /* fewer than two elements */
    }
    swap(v, left, (left + right)/2);
    int last = left;
    for (int i = left+1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsortkr(v, left, last-1, comp);
    qsortkr(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
static int numcmp(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    // printf("[DEBUG] :: s1=%s, s2=%s, v1=%f, v2=%f, res=%d\n", s1, s2 ,v1, v2, (v1<v2) ? -1 : (v1 > v2) ? 1 : 0);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

static int rnumcmp(const char *s1, const char *s2) {
    return numcmp(s2, s1);
}

static int rstrcmp(const char *s1, const char *s2) {
    return strcmp(s2, s1);
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
char *alloc(int n) {    /* return pointer to n characters */
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else { /* not enough room */
        return 0;
    }
}

void afree(char *p) { /* free storage pointed to by p */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

