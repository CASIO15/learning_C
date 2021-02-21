#include "stdio.h"
#define BUFSIZE 10

int getch(void);
void ungetch(int c);

int bufp = 0;
char buf[BUFSIZE];

int getch(void)
{
    if (bufp > 0)
        return buf[--bufp];
    else
        return getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = (char) c;
}
