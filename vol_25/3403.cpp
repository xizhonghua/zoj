//2896314 2012-05-18 14:30:55 Accepted  3403 C++ 20 180 ?????? 
#include<stdio.h>
#include<memory.h>
typedef long long int64;
int64 Y[12] = {0};
int64 M[13] = {0};
int64 SUM = 0;

int64 get_days(int64 y, int64 m, int64 d)
{
    int64 days = 0;
    int64 c = y / 12;
    days += c * SUM;
    for(int64 i=c*12;i<y;i++)
        days += Y[i%12];
    days += (y+10) / 11;
    for(int64 i=1;i<=m-1;i++)
        days += M[i];
    if(y % 11 == 0 && m > 1) days++;
    days += d;
    return days;
}


int main()
{
    for(int64 i=1;i<=12;i++) M[i] = i*i*i;
    for(int64 i=0;i<=11;i++)
    {
        for(int64 j=1;j<=i+1;j++)
            Y[i] += M[j];
        SUM += Y[i];
    }
    
    int64 m1,d1,y1,m2,d2,y2;
    while(~scanf("%lld-%lld-%lld", &m1, &d1, &y1))
    {
        scanf("%lld-%lld-%lld", &m2, &d2, &y2);
        int64 days1 = get_days(y1, m1, d1);
        int64 days2 = get_days(y2, m2, d2);
        printf("%lld\n", days1 > days2 ? days1 - days2 + 1 : days2 - days1 + 1);
    }
}