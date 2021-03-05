#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "qsort.h"
#include "ctype.h"


#define MAXLINES 100
#define MAXLEN 100

char *lineptr[MAXLINES];
int caseFold = 0;
int directory = 0;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, int (*comp) (void *, void *), int reverse);
int numcmp(char *, char *);
int dir_ord(char *, char *);

int main(int argc, char *argv[])
{
    int nlines, numeric, reverse, c;
    numeric = 0;
    reverse = 0;

    while (--argc > 0 && *++argv != NULL)
        if (**argv == '-')
            switch ((c=*++argv[0])) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    caseFold = 1;
                    break;
                case 'd':
                    directory = 1;
                    break;
                default:
                    printf("Unknown commad |%c|\n", c);
                    break;
            }

    if ((nlines=readlines(lineptr, MAXLINES)) >= 0) {
        if (numeric)
            my_qsort((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) numcmp, reverse);
        else if (directory)
            my_qsort((void **) lineptr, 0, nlines-1, (int (*) (void *, void *)) dir_ord, reverse);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getlines(char *s, int lim, int caseFold);

int getlines(char *s, int lim, int caseFold)
{
    int i, c;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++) {
        if (caseFold == 1)
            s[i] = (char) tolower(c);
        else
            s[i] = (char) c;
    }

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len;
    char *p, line[MAXLEN];
    static int nlines = 0;

    while ((len=getlines(line, MAXLEN, caseFold)) > 0)
        if (nlines >= maxlines || (p=malloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; // deleting new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

// lexicographical ordering
int dir_ord(char *s1, char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++, s2++;
    }

    return *s1 - *s2;
}
