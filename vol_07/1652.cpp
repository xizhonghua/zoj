/3113916	2012-11-06 08:07:42	 Accepted	1652	C++	0	180	花花的表世界
#include <stdio.h>
typedef unsigned long long u64;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        n--;
        u64 ans = 2+10*n+9*n*(n-1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}