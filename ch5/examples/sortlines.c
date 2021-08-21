#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000       /* max #lines to be sorted */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsortkr(void *lineptr[], int left, int right,
             int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */

    if (argc > 1 && strcmp(argv[1], "-n") == 0) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsortkr((void**) lineptr, 0, nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too be to sort\n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
int getlinekr(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
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
int numcmp(char *s1, char *s2) {
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* getlinekr: K&R getline; read a line into s, return length */
int getlinekr(char s[], int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
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

