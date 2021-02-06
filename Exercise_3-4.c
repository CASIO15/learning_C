#include <stdio.h>
#include <string.h>
#include <limits.h>


void reverse(char s[]);
void itoa(unsigned int n, char s[]);

int main(void)
{
    char s[100];
    itoa(INT_MIN, s);

    printf("%s\n", s);
}

void reverse(char s[])
{
    int i, j, temp;

    for (i=0, j=strlen(s)-1; i < j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(unsigned int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = n * (-1);
    i = 0;
    do {
        s[i++] =  n % 10 + '0';
    } while ((n/=10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/*
 * We needed to use an unsigned int instead of a signed int, because int can represent only an int of certain size,
 * an unsigned int can represent a larger range of non-negative integers.
 */
