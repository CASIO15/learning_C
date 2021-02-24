#include "stdio.h"
#include "string.h"

void p_itoa(int n, char *s);
void reverse(char *s);


void reverse(char *s)
{
    int length = strlen(s)-1;
    char *start=s, *end= (s+length), temp;

    while (--length > 0) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++, end--;
    }

}



void p_itoa(int n, char *s)
{
    int sign;

    if ((sign=n) < 0) {
        n = -n;
    }

    do {
        *s++ = (char) (n % 10 + '0');
    } while ((n /= 10) > 0);

    if (sign < 0) {
        *s++ = '-';
    }

    *s = '\0';


}


int main(void)
{
    char num[100];
    p_itoa(-1200, num);
    reverse(num);

    printf("%s\n", num);
    return 0;
}
