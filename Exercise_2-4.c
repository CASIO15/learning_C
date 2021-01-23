#include <stdio.h>
#define MAXSIZE 100

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[MAXSIZE] = "Hello, World :)";
    char s2[MAXSIZE] = "Hello";

    squeeze(s1, s2);
    printf("Reuslt: %s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    k = 0;
    i = j = 0;

    while (s1[i] != '\0'){

        if (s1[i] == s2[j])
            j++;
        else {
            s1[k++] = s1[i];
        }
        i++;
    }
    s1[k] = '\0';
}
