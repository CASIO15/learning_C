/*
#include <stdio.h>
#define MAXSIZE 100

int any(const char s1[], const char s2[]);

int main(void)
{
    char s1[MAXSIZE] = "01234567890123456789z";
    char s2[MAXSIZE] = "abcdefghijklmnopqrstuvwxyz";

    printf("Reuslt: %d\n", any(s1, s2));
    return 0;
}

int any(const char s1[], const char s2[])
{
    int i, j;
    i = j = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[j]) {
            return i;
        } else {
            if (s2[j] == '\0') {
                j = 0;
                i++;
            }
        }
        j++;
    }
    return -1;
}
*/
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
