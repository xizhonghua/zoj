//2913503 2012-06-07 10:11:10 Accepted  1160 C++ 200 180 花花的表世界 
#include <stdio.h>

int main()
{
 int N, p, e, i, d, a, c;
 scanf("%d", &N);
 while(N--)
 {
  c = 0;
  while(~scanf("%d %d %d %d", &p, &e, &i, &d))
  {
   if(p == -1 && e == -1 && i == -1 && d == -1) break;
   while(p>=23 && p>d) p-=23;
   while(e>=28 && e>d) e-=28;
   while(i>=33 && i>d) i-=33;
    a = d;
   while(true)
   {
    a++;
    if((a - p) % 23 == 0 && (a - e) % 28 == 0 & (a - i) % 33 == 0) break;
   }
   printf("Case %d: the next triple peak occurs in %d days.\n", ++c, a - d);
  } 
  if(N) printf("\n");
 }
}