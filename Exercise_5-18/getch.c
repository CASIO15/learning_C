#include <stdio.h>

#define BUFFSIZE 100
static char buff[BUFFSIZE];
static int buff_p = 0;

int getch(void);
void ungetch(int c);

int getch(void)
{
    return (buff_p > 0) ? buff[--buff_p] : getchar();
}

void ungetch(int c)
{
    if (buff_p >= BUFFSIZE)
        printf("Buffer is full !\n");
    else
        buff[buff_p++] = (char) c;
}
