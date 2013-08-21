//2893772 2012-05-15 16:10:34 Accepted  1366 C++ 490 276 花花的表世界 
#include<stdio.h>
#include<memory.h>

int N[11], D[11], cash, n, max;
bool dp[100001];
int main()
{
 while(~scanf("%d", &cash))
 {
  scanf("%d", &n);
  for(int i=0;i<n;i++)
   scanf("%d %d", N+i, D+i);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  max = 0;
  for(int i=1;i<=n;i++)
   for(int s=max;s>=0;s--)
    if(dp[s])

     for(int j=0;j<=N[i-1];j++)
     {
      int t = s + j*D[i-1];
      if(t > cash) break;
      if(t > max) { max = t;}
      dp[t] = true;
     }
  printf("%d\n", max);
 }
}