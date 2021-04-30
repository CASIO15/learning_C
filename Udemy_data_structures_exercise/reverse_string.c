#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int len(char *A);
char *split(const char *A);
void reverse(char *A);

int len(char *A)
{
    int cnt=0;

    while (*A++)
        if (*A == ' ')
            cnt++;
    return cnt+1;
}

char *split(const char *A)
{
    static int  i=0;
    int cnt=0, j=0;
    char *temp=(char *)malloc(sizeof(char)*100);

    while (A[i]) {
        temp[j++] = A[i++];
        if (A[i] == ' ' || A[i] == '\0') {
            temp[j] = A[i++];
            temp[++cnt] = '\0';
            break;
        }
        cnt++;
    }
    return temp;
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
