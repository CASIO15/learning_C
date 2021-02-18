#include <stdio.h>

#define MAXSIZE 100
void recursive_itoa(int n, char s[]);
static int counter = 0;

int main()
{
    int n = -144540;
    char s[MAXSIZE];
    
    recursive_itoa(n ,s);
    s[counter] = '\0';

    printf("%s\n", s);
    return 0;
}


void recursive_itoa(int n, char s[])
{
    if (n < 0) {
        s[counter++] = '-';
        n = -n;
    }
    if (n/10)
        recursive_itoa(n / 10, s);


    s[counter++] = (char) (n % 10 + '0');
}
