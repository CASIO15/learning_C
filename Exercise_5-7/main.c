#include "stdio.h"
#include "string.h"
#include "qsort.h"

#define MAXLINES 10

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main()
{
    int nlines;

    if ((nlines=readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        putchar('\n');
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 10
int getlines(char *s, int lim);

int getlines(char *s, int lim)
{
    int i, c;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = (char) c;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len;
    char *p, line[MAXLEN];
    // using static variable so the value wont be reinitialized to 0
    static int nlines = 0;

    while ((len=getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p=(*lineptr + nlines)) == NULL)
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
