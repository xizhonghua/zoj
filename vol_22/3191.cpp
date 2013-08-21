//2892552 2012-05-14 15:47:59 Accepted  3191 C++ 0 180 ?????? 
#include<stdio.h>

int main()
{
 int a;
 while(~scanf("%d", &a) && a!=-1)
 {
  int t = a < 90 ? (90 - a) / 30 : 12 - ( a - 90) / 30;
  if(a % 30 == 0)
   printf("Exactly %d o'clock\n", t == 12 ? 0 : t);
  else
  {
   printf("Between %d o'clock and %d o'clock\n", t-1, t == 12 ? 0 : t);
  }
 }
}