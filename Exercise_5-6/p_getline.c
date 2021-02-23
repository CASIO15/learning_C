#include "stdio.h"
#define MAXSIZE 100

int my_getline(char *s);


int my_getline(char *s)
{
    // We dont need to handle a \n because the function puts, prints the array to the stdin and puts newline for us.
    int i;
    for (i=0; i < MAXSIZE-1 && (*s= (char) getchar()) != EOF && *s != '\n'; s++, i++)
        ;

    *++s = '\0';
    return i;
}


int main()
{
    char *s[MAXSIZE];

    while (my_getline(s) > 0)
        puts(s);

    return 0;
}
