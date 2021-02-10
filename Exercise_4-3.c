/* 
Polish calculator
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;


int getop(char []);
void push(double);
double pop(void);

double atof_(char s[]);
int getch(void);
void ungetch(int c);


int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof_(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("Error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s \n", s);
                break;
        }
    }
    return 0;
}

double atof_(char s[])
{
    double value, power;
    int i, sign, sign_2;

    for (i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (value = 0.0; isdigit(s[i]); i++)
        value = 10.0 * value + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        value = 10.0 * value + (s[i] - '0');
        power *= 10.0;
    }

    if (tolower(s[i]) == 'e') {
        s[i] = 10;
        sign_2 = (s[++i] == '-') ? -1 : 1;
        (sign_2 < 0) ? i++ : 0;

        return (sign * value / power) * pow(10, sign_2 * (s[i] - '0'));

    } else
        return sign * value / power;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else {
        printf("Error: full stack, can\'t push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: empty stack\n");
        return 0.0;
    }
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if (c == '-')
        while (isdigit(s[++i] = c = getch()))
            ;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;


   s[i] = '\0';
   if (c != EOF)
       ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
