#include <stdio.h>  
  
struct tagDate    
{     
    int year;    
    int month;    
    int day;    
};    
  
int SetDate(int y, int m, int d, tagDate *date)    
{     
    date->year = y;    
    date->month = m;    
    date->day = d;    
}     
  
int IsLeapYear(int year)      
{     
    return ((year%4==0) && (year%100!=0)||year%400==0);     
}     
int GetLastDay(tagDate date)     
{     
    int num;    
    switch(date.month)     
    {    
    case  1:    
    case  3:    
    case  5:    
    case  7:    
    case  8:    
    case 10:    
    case 12:    
        num=31;    
        break;    
    case  2:    
        num = 28+IsLeapYear(date.year);     
        break;     
    default:     
        num = 30;     
    }     
    return num;     
}    
  
int IsDateValid(tagDate date)    
{     
    if(date.year <0 || date.month <1 || date.month> 12)     
        return 0;    
    if(date.day <1 || date.day> GetLastDay(date))    
        return 0;    
    return 1;    
}     
  
//date+1    
int AddDay(tagDate *date)    
{    
    date->day++;    
    if(date->day > GetLastDay(*date))    
    {    
        date->day = 1;    
        date->month++;    
        if(date->month > 12)    
        {    
            date->month = 1;    
            date->year++;    
        }    
    }    
}    
  
int Compare(tagDate date1, tagDate date2)    
{    
    if(date1.year < date2.year)    
        return 1;    
    if(date1.year <= date2.year && date1.month < date2.month)    
        return 1;    
    if(date1.year <= date2.year && date1.month <= date2.month && date1.day < date2.day)    
        return 1;    
    return 0;    
}     
  
long DateDiff(tagDate date1, tagDate date2)    
{    
    long delta = 0;    
    tagDate date3;    
    if(!Compare(date1, date2))    
    {    
        date3 = date2;    
        date2 = date1;    
        date1 = date3;    
    }    
    while(Compare(date1,date2))    
    {    
        AddDay(&date1);    
        delta++;    
    }    
    return delta;    
}     
  
int main()    
{    
    tagDate date1, date2;    
    int y, m, d;    
        scanf("%d/%d/%d", &y, &m, &d);    
        SetDate(y, m, d, &date1);  
        scanf("%d/%d/%d", &y, &m, &d);    
        SetDate(y, m, d, &date2);    
  
        printf("%ld\n", DateDiff(date1,date2));  
}  