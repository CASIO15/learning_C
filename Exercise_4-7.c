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
    char s[MAXSIZE] = "tomer";
    ungets(s);

    // putting the chars from getch to the input
    while (i < MAXSIZE) {
        putchar(getch());
        i++;
    }
    return 0;
}

// filling the buffer of ungetch.
void ungets(char s[])
{
    int len = strlen(s);

    while (len)
        ungetch(s[--len]);
}

// when the buff_pos is greater than zero, it returns the buff elements in reverse, so the reversed string of
// ungetch becomes regular again
int getch(void)
{
    return (buff_pos > 0) ? buff[--buff_pos] : getchar();
}

// ungetch gets the letters reversed and inserts them to the buffer
void ungetch(int c)
{
    if (buff_pos >= MAXSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[buff_pos++] = c;
}
