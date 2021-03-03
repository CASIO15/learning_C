#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB 8
#define MAXLINE 1000

int my_getline(char *s, int lim);
void entab(char *s, char *newArr, int pad, int step);

int main(int argc, char *argv[])
{
    char s[MAXLINE], new[MAXLINE];
    int start, step, c, cp_argc=argc;

    while (--argc > 0 && ++argv)
        if ((*argv)[0] == '+' || (*argv)[0] == '-')
            while ((c=(*argv)[1]) && --argc) {
                switch (c) {
                    case 'm':
                        start = atoi(*++argv);
                        break;
                    case 'n':
                        step = atoi(*++argv);
                        break;
                    default:
                        printf("find: illegal option %c\n", c);
                        break;
                }
        }

    if (cp_argc == 1)
        printf("Usage: entab -m <start> +n <step>\n");
    else {
        while(my_getline(s, MAXLINE) > 0) {
            if (argc > 1)
                    entab(s, new, start, step);
            else
                entab(s, new, 1, TAB);
        }
        printf("%s\n", new);
    }

    return 0;
}

int my_getline(char *s, int lim)
{
    int i, c;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; s++, i++)
        *s = c;

    if (c == '\n') {
        *s = c;
        ++s;
    }
    *s = '\0';
    return i;
}

void entab(char *s, char *newArr, int pad, int step)
{
    int i, tabindex;

    i=0;
    while (i++ < pad) {
        *newArr++ = *s++;
    }

    for (i=1; *s != '\0'; i++) {
        tabindex = step - ((i - 1) % step);
        if ((int) *s == ' ' && (tabindex % pad == 0)) {
            *newArr++ = '\t';
            while(isblank(*s) && tabindex)
                s++, tabindex--;
        }
        else {
            if ((int) *s == ' ')
                *newArr++ = ' ';
            else
                *newArr++ = *s;
            s++;
        }
    }
    *newArr = '\0';
}
