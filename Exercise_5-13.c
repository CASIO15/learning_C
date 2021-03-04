#include "stdio.h"
#include "string.h"
#include "aloc.h"
#include "stdlib.h"

#define MAXLINES 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int step);


int main(int argc, char *argv[])
{
    int nlines, cut_off, c, step=0, cp_argc;
    cp_argc = argc;

    while (--argc > 0 && *++argv != NULL)
        if (**argv == '-')
            switch ((c= *++argv[0])) {
                case 'n':
                    cut_off = atoi(*++argv);
                    break;
                default:
                    printf("Unknown command |%c|\n", c);
                    break;
            }

    if (cp_argc == 0)
        printf("Usage: tail -n <number of lines>\n");

    else {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            if (cp_argc > 2) {
                step = nlines - cut_off;
                writelines(lineptr, step, cut_off);
            } else {
                step = nlines - 10;
                writelines(lineptr, step, 10);
            }
        } else {
            printf("Error: input too big to sort\n");
            return 1;
        }
        return 0;
    }
}

#define MAXLEN 100
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
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len=getlines(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; // deleting new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

void writelines(char *lineptr[], int nlines, int step)
{
    lineptr += nlines;
    printf("RESULT <LAST %d LINE>\n", step);

    while (step-- > 0)
        printf("%s\n", *lineptr++);
}
