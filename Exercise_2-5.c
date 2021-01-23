#include <stdio.h>
#define MAXSIZE 100

int any(const char s1[], const char s2[]);

int main(void)
{
    char s1[MAXSIZE] = "xxxabcabc";
    char s2[MAXSIZE] = "cbaa";

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
        } else if (s1[i] != s2[j]) {
            if (s2[j] == '\0') {
                j = 0;
                i++;
            }
        }
        j++;
    }
    return -1;
}
