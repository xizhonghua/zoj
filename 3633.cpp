//3109909	2012-11-01 05:13:36	 Accepted	3633	C++	3040	2132	花花的表世界
#include<stdio.h>
#include<set>
#define MAXN 500001
int d[MAXN];
int n, m, u, v;

int isOK()
{
    std::set<int> s;
    for(int i=v-1;i>=u-1;i--)
    {
        if(s.count(d[i])>0) return d[i];
        s.insert(d[i]);
    }
    return -1;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;i++)
            scanf("%d", d+i);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &u, &v);
            int result = isOK();
            if(result>0) printf("%d\n", result); else printf("OK\n");
        }
        printf("\n");
    }    
}