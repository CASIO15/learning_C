#include <stdio.h>
#define MAXSIZE 1000

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[MAXSIZE] = "abcd0000efg";
    char s2[MAXSIZE] = "0000000000abcd";

    squeeze(s1, s2);
    printf("Reuslt: %s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i=0; s2[i] != '\0'; i++) {
        // printf("%c\n", s2[i]);
        for (j=k=0; s1[j] != '\0'; j++){
            if (s1[j] == s2[i]){
            } else
                s1[k++] = s1[j];
        }
        s1[k] = '\0';
    }
}
