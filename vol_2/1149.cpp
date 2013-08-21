//2893646 2012-05-15 14:48:56 Accepted  1149 C++ 480 1000 花花的表世界 
#include<stdio.h>
#include<memory.h>
int n[6], sum;
bool dp[6+1][20000*6+1];

int solve()
{
 if(sum % 2 == 1) return 0;

 memset(dp, 0, sizeof(dp));
 dp[0][0] = true;

 for(int i=1;i<=6;i++)
  for(int s=sum;s>=0;s--)
   if(dp[i-1][s])
   {
    for(int j=0;j<=n[i-1];++j)
     dp[i][s+j*i] = true;
   }
 return dp[6][sum/2];
}
int main()
{
 int c = 0;
 while(true)
 {
  sum = 0;
  for(int i=0;i<6;i++)
  {
   scanf("%d", n+i);
   sum += (i+1)*n[i];
  }
  if(sum == 0) break;
  printf("Collection #%d:\n", ++c);
  printf("Can%s be divided.\n\n", solve() ? "" : "'t");
 }
}