#include <stdio.h>

#define MAXSTR 1000

void squeeze(char str1[], char str2[]);

int main(void)
{
    char str1[MAXSTR] = ")hello world :)";
    char str2[MAXSTR] = ":)aeiou";

    squeeze(str1, str2);

    printf("Result: %s", str1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    k = 0;
    j = 0;

    for(i=0; s1[i] != '\0';){
        if (s2[j] == '\0'){
            s1[k++] = s1[i];
            i++;
            j = 0;
        } if (s1[i] == s2[j]) {
            ++i;
        }
        j++;
    }
    s1[k] = '\0';
}
