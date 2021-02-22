#include "stdio.h"
#include "string.h"


int strend_1(char *s, char *t);

int strend_1(char *s, char *t)
{
    int counter = 0;
    unsigned int t_length = strlen(t);

    // iterating over s until '\0'
    while (*s++)
        if (*s == '\0')
            break;

    // iterating over t until '\0'
    while (*t++)
        if (*t == '\0')
            break;

    // iterating backwards, checking equality of each char
    while(*--s == *--t)
        counter++; // updating counter

    // if the counter is equal to the length of the t string, return 1
    if (counter == t_length)
        return 1;
    else
        return 0;
}

int main()
{
    char s[] = "hello world", t[] = "ld";

    printf("%d\n", strend_1(s, t));
    return 0;
}
