/*
    modify dcl so that it does not add redundant parentheses to declarations.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char out[1000];

void dcl(void);
void dirdcl(void);
int gettoken(void);

int main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if (type == '*') {
                if (strcmp(token, "()") > 0) // if the token is not a pair of (), we dont need to extra parenthesis around it.
                    sprintf(temp, "*%s", out);
                else
                    sprintf(temp, "(*%s)", out); // if the token is (), then we need to add extra () around the whole declaration
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("Invalid input at %s\n", token);
        printf("%s\n", out);
    }
    return 0;
}

int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); ) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}


void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) {
        strcpy(name, token);
        printf("token: %s\n", token);
    }
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}
