#include <stdio.h>

#define BUFFSIZE 100
static char buff[BUFFSIZE];
static int buff_p = 0;

int getch(void);
void ungetch(int c);

int getch(void)
{
    if (buff_p > 0)
        return buff[--buff_p];
    else
        return getchar();
}

void ungetch(int c)
{
    if (buff_p >= BUFFSIZE)
        printf("Buffer is full !\n");
    else
        buff[buff_p++] = (char) c;
}
