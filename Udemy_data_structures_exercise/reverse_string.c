#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int len(char *A);
char *split(char *A);
void reverse(char *A);

int len(char *A)
{
    int cnt=0;

    while (*A) {
        if (*A == ' ')
            A++, cnt++;
        else
            A++;
    }
    return cnt+1;
}

char *split(char *A)
{
    static int  i=0, j=0, n=0, cnt=0;
    int length=len(A);
    char *temp=(char *)malloc(sizeof(char)*100), *res;

    while (A[i] != '\0') {
        temp[j++] = A[i++];
        cnt++;
        if (A[i] == ' ' || A[i] == '\0') {
            temp[j] = A[i++];
            temp[cnt++] = '\0';
            res = temp;
            j=0, cnt=0, n++;
            return res;
        } if (n == length)
            break;
    }
}

void reverse(char *A)
{
    int i, n, j=len(A)-1;
    char *s[j+1];

    for (i=0; i < len(A); i++)
        s[i] = split(A);

    *A = '\0';
    i=0;
    n=0;
    while (j >= 0) {
        if (strlen(s[j]) > n) {
            A[i++] = s[j][n++];
        } else {
            A[i++] = ' ';
            j--, n=0;
        }
    }
    A[i] = '\0';
}

int main(void)
{
    char string[] = "Process finished with exit code 0";

    reverse(string);
    printf("%s\n", string); // 0 code exit with finished Process

    return 0;
}
