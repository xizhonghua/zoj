//2895808 2012-05-17 16:39:43 Accepted  3508 C++ 30 992 花花的表世界 
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

struct solider{
    int min;
    int max;
}s[2501];

bool cmp(const solider &a, const solider &b)
{
    return a.max < b.max;
}

int main()
{
    int n, m, w;
    multiset<int>::iterator iter;
    while(~scanf("%d %d", &n , &m))
    {
        multiset<int> wp;
        for(int i=0;i<n;i++)
            scanf("%d %d", &s[i].min, &s[i].max);
        for(int i=0;i<m;i++)
        {
            scanf("%d", &w);
            wp.insert(w);
        }
        int ans = 0;
        sort(s, s+n, cmp);
        for(int i=0;i<n;i++)
        {
            iter = wp.lower_bound(s[i].min);
            if(iter != wp.end() && *iter <= s[i].max)
            {
                ans ++;
                wp.erase(iter);
            }
        }
        printf("%d\n", ans);
    }
}
