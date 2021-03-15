#include "stdio.h"

double cos_series(int n, int count);

double cos_series(int n, int count)
{
    static double pow=1, fact=1, sign = 1.0;
    double r;

    if (count == 0)
        return 1.0;

    else {
        r = cos_series(n, count-2);
        pow *= (n*n);
        fact *= (count * (count-1));
        sign *= -1;
        return sign * ((r*sign) + (pow / fact));
    }
}


int main()
{
    printf("%lf\n", cos_series(4,8));
    return 0;
}

