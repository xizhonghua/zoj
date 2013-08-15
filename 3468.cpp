//2892351 2012-05-14 10:29:25 Accepted  3468 C++ 0 180 花花的表世界 
#include <stdio.h>
#include <math.h>
#include <memory.h>
#define MAX_DIES 8
#define MAX_POINTS 6*MAX_DIES

int main()
{
 int dp[MAX_DIES+1][MAX_POINTS+1];
 double ans[MAX_DIES+1][MAX_DIES+1];

 memset(dp, 0, sizeof(dp));
 memset(ans, 0, sizeof(ans));

 dp[0][0] = 1;

 for(int i=1;i<=MAX_DIES;i++)
  for(int j=0;j<=MAX_POINTS;j++)
    for(int k=1;k<=6;k++)
     dp[i][j+k] += dp[i-1][j];

 for(int i=1;i<=MAX_DIES;i++)
  for(int j=1;j<=MAX_DIES;j++)
   for(int k=i*1;k<=i*6;k++)
    for(int l=j*1;l<k;l++)
     ans[i][j] += 1.0 * dp[i][k]*dp[j][l] / pow(6.0, i+j);

 int m, n;
 while(~scanf("%d %d", &m, &n))
 {
  printf("%0.16lf\n", ans[m][n]);
 }
}