//2893839 2012-05-15 16:37:12 Accepted  1582 C++ 0 180 花花的表世界 
#include<stdio.h>
#include<string.h>

int main()
{
 int n, t;
 char typed[81], corrected[81];
 scanf("%d", &n);
 while(n--)
 {
  scanf("%d", &t);
  getchar();
  gets(corrected);
  gets(typed);
  int lc = strlen(corrected);
  int lt = strlen(typed);
  int i=0;
  while(i<lt && i<lc && typed[i] == corrected[i]) i++;
  int ans = lt + lc - 2*i;
  printf("%d\n", ans*t);
 }
}