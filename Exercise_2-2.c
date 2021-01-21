#include <stdio.h>


enum MAXSIZE {max=1000};

int getline1(char s[], int lim);

int main(void)
{
    char s[max];

    getline1(s, max);
    printf("%s\n", s);
    return 0;
}

int getline1(char s[], int lim)
{
    int c, i;

    for (i=0; (c=getchar()) != EOF; i++){
        if (i < max-1)
            if (c != '\n'){
                s[i] = c;
            }
    }

    if (c == '\n'){
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}
