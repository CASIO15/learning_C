#include "stdio.h"
#include "ctype.h"

#define BUFSIZE 10

int bufp = 0;
char buf[BUFSIZE];

int getch(void);
void ungetch(int c);
int getint(int *pn);

int getint(int *pn)
{
    int c, sign, *pc;

    while (isspace(c=getch()))
        ;
    if (!isdigit(c) && c != '+' && c != '-') {
        pc = &c; // creating a pointer to c, though it is not necessary.
        printf("Invalid char %c\n", *pc);
        return *pn = 0; // setting the position in the array to 0.
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn=0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c-'0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}


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
        buf[bufp++] = c;
}


int main()
{
    int n, array[BUFSIZE];

    for(n=0; n < BUFSIZE && getint(&array[n]) != EOF; n++)
        ;

    for (n = 0; n < BUFSIZE; n++)
        printf("%d\n", array[n]);

    return 0;

}
