#include "stdio.h"
#include "ctype.h"
#include "getch.h"

#define BUFSIZE 5


int getfloat(double *pn);

int getfloat(double *pn)
{
    int c, sign, *pc, remainder_arr[BUFSIZE], counter=0, n;
    int zero_pad=1, *pzero_p, sum=0, zero_pcp;
    double reminder=0.0;

    while (isspace(c=getch()))
        ;
    if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
        pc = &c;
        printf("Invalid char %c\n", (int) *pc);
        return *pn = 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

   for (*pn=0; isdigit(c) || c == '.'; c=getch()) {
       if (c == '.') {
           while (isdigit(c=getch())) {
               remainder_arr[counter++] = (c - '0'); // gathering all the digits after the "." to an array
               pzero_p = &zero_pad;
               *pzero_p *= 10; // multiplying the zero pad by 10
               zero_pcp = zero_pad;
           }
           ungetch(c);

           // extracting the digits from the array and adding them to the sum variable
           for (n=0; n < counter && zero_pad > 0; n++, zero_pad/=10)
               sum += remainder_arr[n] * zero_pad;
           // converting the sum to a reminder by dividing it by the zero_pad copy (zero_pcp)
           reminder += (double) sum / (zero_pcp * 10);
       } else
            *pn = (10 * *pn + (c - '0'));
       // adding the reminder to the number that pn points to
       *pn += reminder;
   }

   *pn *= sign;

   if (c != EOF)
        ungetch(c);
    return c;
}


int main()
{
    int n;
    double array[BUFSIZE];

    for(n=0; n < BUFSIZE && getfloat(&array[n]) != EOF; n++)
        ;

    for (n = 0; n < BUFSIZE; n++)
        printf("%g\n", array[n]);

    return 0;

}
