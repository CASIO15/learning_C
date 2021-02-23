#include "stdio.h"

void strncpy(char *s, char *t, int n);

void strncpy(char *s, char *t, int n)
{
    int counter = 0;

    while (counter++ < n) {
        *s++ = *t++;
    }
    *s = '\0';
}

int main()
{
    char s[] = "Hello, ", t[] = "hello world !";
    strncpy(s, t, 10);
    printf("%s\n", s);

    return 0;
}
