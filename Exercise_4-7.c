#include <stdio.h>
#include <string.h>


#define MAXSIZE 100
char buff[MAXSIZE];
int buff_pos = 0;


void ungets(char s[]);
void ungetch(int c);
int getch(void);

int main(void)
{
    int i = 0;
    char s[MAXSIZE] = "4444";
    ungets(s);

    while (i < MAXSIZE) {
        putchar(getch());
        i++;
    }
    return 0;
}


void ungets(char s[])
{
    int len = strlen(s);

    while (len)
        ungetch(s[--len]);
}

int getch(void)
{
    return (buff_pos > 0) ? buff[--buff_pos] : getchar();
}

void ungetch(int c)
{
    printf("%d\n", buff_pos);
    if (buff_pos >= MAXSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[buff_pos++] = c;
}
