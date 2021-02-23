#include "stdio.h"


int strncmp(char *s, char *t, int n);

int strncmp(char *s, char *t, int n)
{
    while (*s++ && *t++ && (--n > 0)) {
        if (*s == *t)
            continue;
        else
            return *s - *t;
    }

    return 0;
}

int main()
{
    char *s = "Hello world", *t = "Hello world !";
    int x = strncmp(s, t, 7);

    (x == 0) ? puts("Strings are equal.") : puts("Strings are not equal.");
    return 0;
}
