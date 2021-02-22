#include "stdio.h"
#define MAXSIZE 100

int strend(char *s, char *t);

int strend(char *s, char *t)
{
    while (*s)
        if (*s++ == *t)
            t++;

    if (*s == *t)
        return 1;
    else
        return 0;
}

int main()
{
    char s[MAXSIZE] = "hello world", t[MAXSIZE] = "ld";

    printf("%d\n", strend(s, t));
    return 0;
}
