#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 1000

double atof(char s[]);

int main(void)
{
    char line[MAXLINE] = "123.45e-6";
    printf("%g\n", atof(line));
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign, sign_2;

    for (i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (tolower(s[i]) == 'e'){
        s[i] = 10;
        sign_2 = (s[++i] == '-') ? -1 : 1;
        return (sign * val / power) * pow(10, sign_2 * (s[++i] - '0'));

    } else
        return sign * val / power;
}
