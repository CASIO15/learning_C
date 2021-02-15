#include <stdio.h>

#define MAXSIZE 100
char buff[MAXSIZE];
int buff_pos = 0;


void ungetch(int c);
int getch(void);

int main(void)
{
    int c;
    printf("To exit use ^c.\n");
    while ((c=getchar())) {
        ungetch(c);
        printf("%c\n", getch());
    }
    return 0;
}


int getch(void)
{
    buff_pos=0;

    while (buff_pos >= 0) {
        if(buff[buff_pos] == EOF) {
            ungetch(EOF);
        }
        else  {
            buff[++buff_pos] = '\0';
            return buff[--buff_pos];
        }
    }
}


void ungetch(int c)
{
    if (buff_pos >= MAXSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[buff_pos++] = c;
}
