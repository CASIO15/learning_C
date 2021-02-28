#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define MAXVAL 100


int sp = 0;
double val[MAXVAL];

void push(double);
double pop(void);


int main(int argc, char *argv[])
{
    double op2;
    argv += 1;
    while (*++argv != NULL && --argc > 0) {
        if (!isalpha(*argv[0])) {
            switch (*argv[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    if (op2 == 0)
                        printf("error: zero division\n");
                    else
                        push(pop() / op2);
                case '%':
                    op2 = pop();
                    push((int) pop() % (int) op2);
                    break;
                default:
                    push(atof(*argv));
                    break;
            }
        } else {
            printf("Invalid !\n");
            printf("Usage RPN: \n");
            printf("Example: 2 3 4 + * --> 2 * (3 + 4)\n");
        }
    }
    printf("%g\n", pop());
    return 0;
}


void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: full stack, can\'t push %g\n", f);
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
