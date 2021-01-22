#include <stdio.h>
#include <ctype.h>
#include <math.h>


double htoi(char s[]);

int main()
{
    char s[] = "0xabcdef";
    printf("Get the integer value of the hex \'%s\':\n", s);
    printf("%.0f\n", htoi(s));
    return 0;
}

double htoi(char s[])
{
    int i, counter;
    double sum;
    sum = 0.0;
    counter = -1;

    for(i=0; s[i] != '\0'; i++) {
        if (!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f') && !isdigit(s[i])){
            printf("letter \'%c\' is not valid !\n", s[i]);
        } else if (s[i] == '0' && tolower(s[++i]) == 'x'){
        } else {
            ++counter;
        }
    }

    for(i=2; s[i] != '\0' && counter >= 0; i++){
        if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'){
            sum = sum + (tolower(s[i]) - 87) * pow(16, counter--);
        } else if (isdigit(s[i])) {
            sum = sum + (s[i] - 48) * pow(16, counter--);
        }
    }
    return sum;
}
