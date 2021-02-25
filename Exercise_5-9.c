#include "stdio.h"


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pday, int *pmonth);



static char daytab[2][13] =  {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


int day_of_year(int year, int month, int day)
{
    int leap, i=0;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year % 400 == 0;
    p = &daytab[leap][1]; // pointer points to the correct location of the multi-dimension array

    while (++i < month)
        day += *p++; 

    return day;
}

void month_day(int year, int yearday, int *pday, int *pmonth)
{
    int leap, i=1;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year % 400 == 0;
    p = &daytab[leap][1]; // pointer points to the correct location of the multi-dimension array

    while (yearday > *p) {
        yearday -= *p++;
        i++;
    }

    *pday = yearday;
    *pmonth = i;
}


int main(void)
{
    int day = day_of_year(2021, 12, 31), month, day_;
    month_day(2021, day, &day_, &month);

    printf("Day=%d  Month=%d  %d\n", day_, month, day);

    return 0;
}
