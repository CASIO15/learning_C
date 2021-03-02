#include <stdio.h>
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

#define TAB 8
#define MAXLINE 1000

int my_getline(char *s, int lim);
void entab(char *s, char *newArr, int pad);

int main(int argc, char *argv[])
{
    char s[MAXLINE], new[MAXLINE];

    if (argc <= 1)
            printf("Usage: entab <list of tab stops>\n");
    else {
        while (my_getline(s, MAXLINE) > 0) {
            if (strcmp(argv[1], "entab") == 0 && argc > 2) {
                argv++;
                while (--argc > 0 && *++argv != NULL) {
                    entab(s, new, atoi(*argv));
                }
            } else
                entab(s, new, TAB);
        }
        printf("%s\n", new);
    }
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

void entab(char *s, char *newArr, int pad)
{
    int i, tabindex;

    for (i=1; *s != '\0'; i++) {
        tabindex = pad - ((i - 1) % pad);
        if ((int) *s == ' ' && (tabindex % pad == 0)) {
            *newArr++ = '\t';
            while(isblank(*s) && tabindex)
                s++, tabindex--;
        }
        else {
            if ((int) *s == ' ')
                *newArr++ = ' ';
            else
                *newArr++ = *s;
            s++;
        }
    }
    *newArr = '\0';
}
