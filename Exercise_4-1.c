  GNU nano 5.3                                                            function.c                                                                      
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

char pattern[] = "abc";

int getline_(char line[], int max);
int strindex(char source[], char searchfor[]);

int main(void)
{
    int result;
    char line[MAXLINE];

    while(getline_(line, MAXLINE) > 0){
        if ((result=strindex(line, pattern)) >= 0)
            printf("%d", result);
        break;
    }
    return 0;
}

int getline_(char s[], int lim)
{
    int c, i;

    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k, len, current_idx;
    len = strlen(t);

    for (i=0; s[i] != '\0'; i++){
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            current_idx = j;
        if (s[i] == '\n') {
            return current_idx - len + 1;
          }
        }
    return -1;
}
