#include <stdio.h>

int main()
{
    int t, a, b, c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int min = 0;
        int max = 0;
        
        {
            int combo = 0;
            for(int i=0;i<c;i++,combo++)
                max += 50*(combo*2+1);
            for(int i=0;i<b;i++,combo++)
                max += 100*(combo*2+1);
            for(int i=0;i<a;i++,combo++)
                max += 300*(combo*2+1);
        }
        {
            int combo = 0;
            for(int i=0;i<a;i++,combo++)
                min += 300*(combo*2+1);
            for(int i=0;i<b;i++,combo++)
                min += 100*(combo*2+1);
            for(int i=0;i<c;i++,combo++)
                min += 50*(combo*2+1);
        }

       printf("%d %d\n",min,max);
    }
}
