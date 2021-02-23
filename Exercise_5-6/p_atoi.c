#include "stdio.h"
#define MAXSIZE 100

int atoi(char *s);


int atoi(char *s)
{
    int sign=1, sum=0, mult=1;

    if (*s == '-')
        sign = -1;

    // looping over the array until '\0'
    while (*s++ != '\0')
        ;

    s--;

    // looping backwards, mult is multiplied each iteration by 10, and the sum accumulates each digit.
    while (*--s && *s != '-' && *s != '+') {
        sum += ((*s - '0')  * mult);
        mult *= 10;
    }
    return sum * sign;
}


int main()
{
    char *s = "-1649602";

    printf("%d\n", atoi(s));

    return 0;
}
