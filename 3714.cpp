#include <stdio.h>

int main(){
    int t, m, n;
    int c[201];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d", c+i);
        int start = 0, end = 0;
        int sum = 0, max = 0;
        if(m==1)
        {
            for(int i=0;i<n;i++)
                if(c[i]>max) max=c[i];
        }
        else
        {
            while(end != n - 1)
            {
                sum += c[start%n];
                if(start - end == m)
                    sum -= c[end++];
                if(sum>max) max=sum;
                start++;
            }
        }
        printf("%d\n", max);
    }
}
