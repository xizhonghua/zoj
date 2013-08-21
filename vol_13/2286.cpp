//2893922 2012-05-15 17:35:32 Accepted  2286 C++ 560 4084 ?????? 
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#define MAX 1000000
int f[MAX+2];

int main()
{
 memset(f, 0, sizeof(f));
 for(int i=1;i<=MAX;i++)
  f[i] = 1;
 for(int i=2;i<=MAX;i++)
  for(int j=2;j*i<=MAX;j++)
   f[j*i] += i;
 std::sort(f+1, f+MAX+1);
 int n;
 while(~scanf("%d", &n))
 { 
  int i=0;
  for(i=1;i<=MAX;i++)
   if(f[i] > n) break;
  printf("%d\n", i);
 }
}