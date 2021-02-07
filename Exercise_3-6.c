#include <stdio.h>
#include <ctype.h>
#include <string.h>

void itoa(char s[], int n, int padding);
void reverse(char s[], int pad);

int main(void)
{
    char s[1000];
    int n = 1250;
    int pad = 15;
    itoa(s, n, pad);

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

void itoa(char s[], int n, int padding)
{
    int i, sign, j;

    for (i=0; isspace(s[i]); i++)
        ;

    for (j=i, i=padding+1; j <= padding; j++, i++) {
        s[i] = s[j];
        s[j] = ' ';
        }

    sign = (s[j] == '-') ? -1 : 1;
    (sign < 0) ? j++ : j;

    do {
         s[j++] = n % 10  + '0';
    } while ((n /= 10) > 0);

    s[j] = '\0';
    reverse(s, padding);
}
