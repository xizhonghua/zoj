//2894388	2012-05-15 22:13:34	 Accepted	3019	C++	330	256	花花的表世界
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 10000

int a[MAX+1], b[MAX+1];
int N, M;
int main()
{
    while(~scanf("%d %d", &N, &M))
    {
        for(int i=0;i<N;i++)
            scanf("%d", a+i);
        for(int i=0;i<M;i++)
            scanf("%d", b+i);
        sort(a, a+N);
        sort(b, b+M);
        int c = 0, p = 0;
        for(int i=0;i<N;i++)
           for(int j=p;j<M;j++)
                if(a[i] == b[j])
                {
                    ++c;
                    p = j+1;
                    break;
                }
        printf("%d\n", c);
    }
}