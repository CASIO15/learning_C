#include <stdio.h>

int main()
{
    char c;
    c = 'G';

    printf("%c\n", (c >= 'A' && c <= 'Z' ? c + 32 : c));

    return 0;
}
