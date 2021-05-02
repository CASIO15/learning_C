#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int len(char *A);
char *split(char *A);
void reverse(char *A);

int len(char *A)
{
    int cnt=0;

    while (*A++)
        if (*A == ' ')
            cnt++;
    return cnt+1;
}

char *split(char *A)
{
    static int  i=0;
    if (i > strlen(A))
        i=0;
    int cnt=0, j=0;
    char *temp=(char *)malloc(sizeof(char)*20);

    while (A[i]) {
        temp[j++] = A[i++];
        if (A[i] == ' ' || !A[i]) {
            temp[j] = ' ';
            break;
        }
        cnt++;
    }
    temp[++cnt] = '\0';
    return temp;
}

void reverse(char *A)
{
    int length=len(A);
    int i, j=length-1;
    char *s[length];

    for (i=0; i < length; i++)
        s[i] = split(A);

    *A = '\0';

    while (j >= 0)
        strcat(A, s[--j]);

}

int main(void)
{
    char string[] = "  hello            world !!!    ";
    char string2[] = "                               ";

    reverse(string);
    reverse(string2);

    printf("string: %s\n", string); // string:     !!! world            hello

    printf("string2: %s\n", string2); // string2:
    
    return 0;
}
