#include "stdio.h"

static char daytab[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);


int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year % 400 == 0;
    month = (month > 12 || month < 0) ? 12 : month;
    day = (day < 0) ? -day : (day > 31) ? 31 : day;

    if (year <= 0)
        printf("error: Year {%d} is invalid !\n", year);
    else
        for (i = 1; i < month; i++)
            day += daytab[leap][i];
    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year % 400 == 0;

    if (year <= 0)
        printf("error: Year {%d} is invalid !\n", year);
    else
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(void)
{
    int day = day_of_year(2021, 12, 31), month=0, day_=0;
    month_day(2021, day, &month, &day_);

    printf("month=%d day=%d\n",month, day_);

    return 0;
}
