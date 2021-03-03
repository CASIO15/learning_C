#include <stdio.h>
#include <stdlib.h>

#define ISTAB(s) ((s) == '\t') ? 1 : 0
#define TAB 8
#define MAXLINE 1000

int my_getline(char *s, int lim);
void detab(char *s, char *newArr, int pad, int step);

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
        printf("Usage: detab -m <start> +n <step>\n");
    else {
        while(my_getline(s, MAXLINE) > 0) {
            if (argc > 1)
                    detab(s, new, start, step);
            else
                detab(s, new, TAB, 0);
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

void detab(char *s, char *newArr, int pad, int step)
{
    int i, tabindex;

    for (i=step; *s != '\0'; s++, i++) {
        tabindex = pad - ((i - 1) % pad);
        if (ISTAB(*s))
            while((tabindex--) > 0) {
                *newArr++ = ' ';
            }
        else
            *newArr++ = *s;
    }

    *newArr= '\0';
}
