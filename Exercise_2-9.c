#include <stdio.h>

int setbits(unsigned x);

int main()
{
    unsigned int x = 0b111111110000011111010;


    printf("%d\n", setbits(x));
    return 0;
}

int setbits(unsigned x)
{
    int i;
    for(i=0; x != 0; x &= (x-1))
        i++;

    return i;
}
