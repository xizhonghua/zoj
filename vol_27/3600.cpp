//2894243	2012-05-15 20:48:08	 Accepted	3600	C++	0	196	花花的表世界
#include<stdio.h>
#define MAXD 1000
double p[MAXD+1][2];

int round(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}
int main()
{
    double s1 = 10, p1 = 2.0, s2 = 10, p2 = 2.5;
    for(int i=0;i<=MAXD;i++)
    {
        if(i>3)
        {
            s1 += p1;
            s2 += p2;
        }
        if(i == 10)
        {
            p1 = 3.0;
            p2 = 3.75;
        }
        p[i][0] = s1;
        p[i][1] = s2;
    }

    int T, d, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &d, &t);
        int t1 = round(p[d][0] + t * 2.0 / 5);
        int t2 = round(p[d][1] + t * 2.5 / 4);
        printf("%d\n", t2 - t1);
    }
}