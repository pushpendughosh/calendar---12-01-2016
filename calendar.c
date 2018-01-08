//
//  calendar.c
//  My calendar
//
//  Created by PUSHPENDU GHOSH on 12/01/16.
//  Copyright © 2016 PUSHPENDU. All rights reserved.
//  Xcode 7.2 (7C68)
//

#include<stdio.h>

int checkleap ( int year )
{
    if(year%400==0)
        return 2;
    
    else if(year>1700&&year%100==0)
        return 1;
    
    else if(year%4==0)
        return 2;
    
    else return 1;
}

int daysinmonth (int month,int year)
{
    if(year==1752&&month==9)
        return 19;
    
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    else if(month==4||month==6||month==9||month==11)
        return 30;
    else if(checkleap(year)==2)
        return 29;
    else
        return 28;
}
int actdaysinmonth (int month,int year)
{
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
            return 31;
        else if(month==4||month==6||month==9||month==11)
            return 30;
        else if(checkleap(year)==2)
            return 29;
        else
            return 28;
}
int firstday ( int year )
{
    int i,days=0;
    
    for(i=1;i<year;i++)
    {
        days+=checkleap(i);
    }
    if(year>=1753)
        return ((6+days+3)%7);
    return ((6+days)%7);
}

int monthstart(int month,int year)
{
    int Jan1day,days=0,i;
    Jan1day = firstday(year);
    
    for(i=1;i<month;i++)
        days+=daysinmonth(i,year);
    
    return (firstday(year)+(days%7))%7;
}
void display(int month,int year)
{
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");
    int i=monthstart(month,year);
    int j;
    for(j=i;j>0;j--)
        printf("    ");
    for(j=1;j<=actdaysinmonth(month,year);j++)
    {
        if(year==1752&&month==9&&j==3)
        {
            j=14;
            i-=4;
        }
        if(j<10)printf(" %d  ",j);
        else printf(" %d ",j);
        
        if((i+j)%7==0)
            printf("\n");
    }
    printf("\n");
}
int main ()
{
    int year,month;
    
    printf("Enter year : ");
    scanf("%d",&year);
    
    printf("Enter month : ");
    scanf("%d",&month);
    
    display(month,year);
    
    return 0;
}