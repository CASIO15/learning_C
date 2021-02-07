#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void my_itoa(char s[], int n, int padding);
void reverse(char s[], int pad);



int main(void)
{
    char s[1000];
    int n = -1250;
    int pad = 15;
    my_itoa(s, n, pad);

    printf("%s\n", s);
    return 0;
}

void reverse(char s[], int padding)
{
    int i, c, j;

    for(i=padding, j=strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void my_itoa(char s[], int n, int padding)
{
    int i, sign, j;

    for (i=0; isspace(s[i]); i++)
        ;

    for (j=i, i=padding; j <= padding; j++, i++) {
        s[i] = s[j];
        s[j] = ' ';
        }

    sign = (n < 0) ? -1 : 1;

    do {
         s[j++] = abs(n % 10) + '0';
    } while (abs((n /= 10)) > 0);

    if (sign < 0)
        s[j++] = '-';

    s[j] = '\0';
    reverse(s, padding);
}
