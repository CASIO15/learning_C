#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

void escape(char const s[], char t[]);
void reverse_escape(char const s[], char t[]);

int main()
{
    char s[MAXSIZE] = "\t\t\t\thello\t\tworl\n\nd\n";
    char t[strlen(s)+1];
    
    char original[MAXSIZE] = "\\tCASIO15\\nhello\\n";
    char new[strlen(original)];

    escape(s, t);
    reverse_escape(original, new);

    printf("%s\n", t);
    printf("%s", new);

    return 0;
}

void escape(char const s[], char t[])
{
    int i, j;

    for (i=j=0; i < strlen(s)+1; ++i, ++j){
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
}

void reverse_escape(char const s[], char t[])
{
    int i, j;
    for (i=j=0; i < strlen(s)+1; i++, j++) {
        switch (s[i]) {
            case '\\':
                switch (s[++i]){
                    case 't':
                        t[j] = '\t';
                        break;
                    case 'n':
                        t[j] = '\n';
                        break;
                }
                break;
            default:
                t[j] = s[i];
                break;
        }
    }
}
