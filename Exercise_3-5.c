#include <stdio.h>
#include <string.h>
#include <ctype.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
void expand(const char s1[], char s2[]);


int main(void)
{
    char s[100];
    int n = 1250;
    int b = 16;

    itob(n, s, b);
    printf("The result for %d in base %d is: %s\n", n, b, s);
}

void reverse(char s[])
{
    int i, j, c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void expand(const char s1[], char s2[])
{
    int i, j, n;

    n = 0;
    for (i=0; i < strlen(s1)-1; ){
        if (ispunct(s1[i])) {
            i++;
        } else {
            for (j = (int) s1[i]; j <= (int) s1[i+2]; n++, j++) {
                s2[n] = (char) j;
            }
            i++;
        }
    }
    s2[n] = '\0';
}

void itob(int n, char s[], int b)
{
    int i, sign;

    char s2[100] = "0-9A-Z";
    char alpha[100];
    expand(s2, alpha);

    if ((sign = n) < 0)
        n = -n;
    
    i = 0;
    do{
        s[i++] = alpha[n % b];
    } while ((n /= b) > 0);

    if (sign<0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}
