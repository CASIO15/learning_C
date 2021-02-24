#include "stdio.h"
#include "string.h"

void reverse(char *s);

void reverse(char *s)
{
    int length = (int) strlen(s);
    char *start, *end, temp;

    start = s;
    end = (s + length-1);

    while (--length > 0) {
        temp = *start; 
        *start = *end; 
        *end = temp; 

        start++, end--;
    }
}


int main(void)
{
    char name[100] = "Tomer";
    reverse(name);

    printf("%s\n", name);
    return 0;
}
