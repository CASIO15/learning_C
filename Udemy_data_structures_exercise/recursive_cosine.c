#include "stdio.h"

/*
    cosine series = 1 - xˆ2/2! + xˆ4/4! - xˆ6/6! ...
*/

double cosine_series(int n, int count);

double cosine_series(int n, int count)
{
    static double pow=1.0, fact=1.0, sign = 1.0;
    double r;

    if (count == 0)
        return 1.0;

    else {
        r = cosine_series(n, count-2); // head recursion, so all calculation are done at return time.
        pow *= (n*n); // calculating power of n
        fact *= (count * (count-1)); // calculating factorial 
        sign *= -1.0;
        return sign * ((r*sign) + (pow / fact));
    }
}


int main()
{
    printf("%lf\n", cosine_series(4,8));
    return 0;
}

