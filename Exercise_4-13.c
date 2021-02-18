#include <stdio.h>
#include <string.h>
#define MAXSIZE 100


void recursive_reverse(char s[], int start, int stop);


void recursive_reverse(char s[], int start, int stop)
{
    char temp;

    if (start < stop) {
        recursive_reverse(s, start+1, stop-1);
        temp = s[start];
        s[start] = s[stop];
        s[stop] = temp;
    }
}


int main()
{
    char s[MAXSIZE] = "hello world !";
    int start=0, stop= (int) strlen(s)-1;

    recursive_reverse(s, start, stop);

    printf("%s\n", s);

    return 0;
}
