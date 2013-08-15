//2912985 2012-06-06 15:40:02 Accepted  1171 C++ 120 180 花花的表世界 
#include<stdio.h>

int main()
{
 char p[100002];
 int T, n;
 scanf("%d", &T);
 while(T--)
 {
  scanf("%d", &n);
  for(int i=0;i<n;)
  {
   scanf("%c", p+i);
   if(p[i] == 'U' || p[i] == 'D') i++;
  }
  int c = 0, pos = 0;
  for(int i=1;i<n;i++)
   if(p[i] != p[pos])
   {
    pos = i;
    c++;
   }  
  printf("%d\n", c);
  if(T) printf("\n");
 }
}