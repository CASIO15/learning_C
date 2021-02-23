#include "stdio.h"

void strncat(char *s, char *t, int n);

void strncat(char *s, char *t, int n)
{
    n -= 1;

    while (*s++)
        if (!*s)
            break;

    while ((*s++ = *t++) && n-- > 0)
        ;

    *s = '\0';
}

int main()
{
    char s[] = "Hello, ", t[] ="world !";
    strncat(s, t, 3);
    printf("%s\n", s);

    return 0;
}
