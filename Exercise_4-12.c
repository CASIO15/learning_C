#include <stdio.h>
#define MAXSIZE 100

void recursive_itoa(int n, char s[]);

int main()
{
    char s[MAXSIZE];

    recursive_itoa(826, s);
    printf("%d is converted to %s.\n", 826, s);
    recursive_itoa(-2093, s);
    printf("%d is converted to %s.\n", -2093, s);

    return 0;
}


void recursive_itoa(int n, char s[])
{
    static int counter = 0, call = 0;
    call++;

    if (n < 0) {
        s[counter++] = '-';
        n = -n;
    }

    if (n/10) {
        recursive_itoa(n / 10, s);
    }

    s[counter++] = (char) (n % 10 + '0');
    s[counter] = '\0';

    call--;
    if (call == 0)
        counter = 0;
}
