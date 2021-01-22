#include <stdio.h>
#include <ctype.h>
#include <math.h>

enum SIZE {max=100};

double htoi(char s[]);

int main()
{
    char s[max] = "0xff";
    printf("Get the integer value of the hex \'%s\':\n", s);
    printf("\nResult: %.0f\n", htoi(s));
    return 0;
}

double htoi(char s[])
{
    int i, counter;
    double sum;
    sum = 0.0;
    counter = 0;

    for(i=0; s[i] != '\0'; i++) {
        if (!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f') && !isdigit(s[i])){
        } else if (s[i] == '0' && tolower(s[i+1]) == 'x'){
        } else {
            ++counter;
        }
    }

    for(i=0; s[i] != '\0' && counter >= 0; i++){
        if (s[i] == '0' && tolower(s[++i]) == 'x') {
            i = 2;
        }
        if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'){
            sum = sum + (tolower(s[i]) - 87) * pow(16, --counter);
            printf("(%d x 16 ** %d) = %.0f\n", tolower(s[i]) - 87, counter, sum);
        } else if (isdigit(s[i])) {
            sum = sum + (s[i] - 48) * pow(16, --counter);
            printf("(%d x 16 ** %d) = %.0f\n", tolower(s[i]) - 48, counter, sum);
        }
    }
    return sum;
}
