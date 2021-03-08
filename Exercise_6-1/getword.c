#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "getch.h"

#define MAXWORD 1000

struct key {
    char *word;
    int count;
} keytab[] = { // array of the key struct, initializes the *word and count
        "\"", 0,
        "#define", 0,
        "#include", 0,
        "/*", 0,
        "//", 0,
        "_", 0,
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "for", 0,
        "int", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0,
        "{", 0,
        "}", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int);
int binsearch(char *, struct key *, int);

char new[MAXWORD];

int main()
{
    int n;
    char word[MAXWORD], name[] = "hello";
    // comment here
    /* multi line */
    while (getword(word, MAXWORD) != EOF)
        if (isascii(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0 || (n=binsearch(new, keytab, NKEYS)) >= 0)
                keytab[n].count++;

    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0)
            printf("RESULT: %4d %s\n", keytab[n].count, keytab[n].word);
    }
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;

    while (low <= high) {
        mid = (low+high)/2;
        if ((cond=strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getword(char *word, int lim)
{
    int c;
    char *w = word, *under = new;

    while (isspace(c=getch()))
        ;
    if (c != EOF)
        *w++ = c;

    for (; --lim; w++) {
        if (!isspace(c=getch()) && c != '\n' && !isblank(c)) {
            if (c == '_' || c == '"') {
                *under = c;
                return c;
            } else
                *under = '\0';
            *w = c;
        } else {
            *w = '\0';
            ungetch(c);
            break;
        }
    }
    return c;
}
