#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 100

void expand(char s1[], char s2[]);

int main()
{
    char s[MAXSIZE] = "a-z0-9";
    char s2[MAXSIZE];

    expand(s, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, n;

    n = 0;
    for (i=0; i < strlen(s1)-1; ){
        if (ispunct(s1[i])) {
            i++;
        } else {
            for (j = (int) s1[i]; j <= (int) s1[i+2]; n++, j++) {
                s2[n] = (char) j;
            }
            i++;
        }
    }
    s2[n] = '\0';
}

