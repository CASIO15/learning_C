#include "stdio.h"
#define MAXSIZE 100

void strcat2(char *s, char *t);

void strcat2(char *s, char *t)
{
    // looping over the string s
    while (*s++){
        if (!*s) // if s is 0
            while ((*s++ = *t++) != '\0') // copying t to the end of s.
                ;
    }
}

int main()
{
    char s[MAXSIZE] = "CASIO15", t[MAXSIZE] = ", hello world";
    strcat2(s, t);

    printf("%s\n", s);
    return 0;
}
