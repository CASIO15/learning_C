#include <stdio.h>
#include "stdlib.h"

#define TAB 4
#define MAXLINE 1000

int my_getline(char *s, int lim);
void entab(char *s, char *newArr, int pad);

int main(int argc, char *argv[])
{
    char s[MAXLINE], new[MAXLINE];

    while(my_getline(s, MAXLINE) > 0) {
        if (argc > 1) {
            while (--argc > 0) {
                entab(s, new, atoi(*++argv));
            }
        }
        else
            entab(s, new, TAB);
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

void entab(char *s, char *newArr, int pad)
{
    int i;

    for (i=1; *s != '\0'; i++) {
        if ((int) *s == ' ' && i % pad == 0)
            *newArr++ = '\t';
        else
            *newArr++ = *s++;
    }
    *newArr = '\0';
}
