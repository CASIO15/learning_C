#include <stdio.h>
#include "stdlib.h"

#define ISTAB(s) (s == '\t') ? 1 : 0
#define TAB 8
#define MAXLINE 1000

int my_getline(char *s, int lim);
void detab(char *s, char *newArr, int pad);

int main(int argc, char *argv[])
{
    char s[MAXLINE], new[MAXLINE];

    while(my_getline(s, MAXLINE) > 0) {
        if (argc > 1) {
            while (--argc > 0) {
                detab(s, new, atoi(*++argv));
            }
        }
        else
            detab(s, new, TAB);
    }

    printf("%s\n", new);
    return 0;
}

int my_getline(char *s, int lim)
{
    int i, c;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; s++, i++)
        *s = c;

    if (c == '\n') {
        *s = c;
        ++s;
    }
    *s = '\0';
    return i;
}

void detab(char *s, char *newArr, int pad)
{
    int i, tabindex;

    for (i=0; *s != '\n'; s++, i++) {
        tabindex = pad - ((i - 1) % pad);
        if (ISTAB(*s))
            while((tabindex--) > 0) {
                *newArr++ = ' ';
            }
        else
            *newArr++ = *s;
    }
    if (*s == '\n')
        *newArr++ = *s;

    *newArr= '\0';
}
