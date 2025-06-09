#include <stdio.h>

typedef struct date{
    int year;
    int month;
    int day;
} date;

int main(){
    date S, E;
    int S_day, E_day;
    int y_leave = 0;
    int m_leave = 0;
    int A;
    // 1년 = 12개월 = 360일
    scanf("%d %d %d", &S.year, &S.month, &S.day);
    S_day = (S.year-1)*360 + (S.month-1)*30 + S.day;
    scanf("%d %d %d", &E.year, &E.month, &E.day);
    E_day = (E.year-1)*360 + (E.month-1)*30 + E.day;

    date work;
    work.day = E_day-S_day;
    work.month = work.day/30;
    work.year = work.month/12;
    A = -1;
    for(int y=1; y<=work.year; ++y){
        if(y%2==1) A++;
        y_leave += A + 15;
    }

    m_leave = work.month>36? 36 : work.month;

    printf("%d %d\n", y_leave, m_leave);
    printf("%ddays", E_day - S_day);

    return 0;
}