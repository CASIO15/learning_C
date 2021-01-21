#include <stdio.h>
#include <string.h>

int my_strlen(char s[]);

int main(void)
{

    char string[] = "Tomer";
    enum month {FALSE, TRUE};

    printf("%d\n", TRUE);

    printf("The strlen from the string lib %d\n", strlen(string));

    printf("The length of %s is, %d.\n", string, my_strlen(string));
    return 0;
}

int my_strlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;

    return i;
}

// ###############################################################################

