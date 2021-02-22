#include "stdio.h"
#include "string.h"


int strend_1(char *s, char *t);

int strend_1(char *s, char *t)
{
    int counter = 0;
    unsigned int t_length = strlen(t);

    // iterating over s and t, until they both points to \0
    while (*s++ && *t++) {
        if (!*s && *t)
            s--;
        else if (!*t && *s)
            t--;
        else if (!*s && !*t)
            break;
    }

    // iterating backwards and checking the equality of each char.
    while(*--s == *--t)
        // updating counter
        counter++;

    // if the counter is equal to the length of t, return 1
    if (counter == t_length)
        return 1;
    else
        return 0;
}

int main()
{
    char s[] = "hello world", t[] = " world";

    printf("%d\n", strend_1(s, t));
    return 0;
}
