#include <stdio.h>

#define BUFSIZE 100
static char buf[BUFSIZE];
static int buf_p = 0;

int getch(void);
void ungetch(int c);

int getch(void)
{
    return (buf_p > 0) ? buf[--buf_p] : getchar();
}

void ungetch(int c)
{
    if (buf_p >= BUFSIZE)
        printf("Input too big\n");
    else
        buf[buf_p++] = c;
}
