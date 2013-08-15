/2893302 2012-05-15 09:57:44 Accepted  3326 C++ 150 180 花花的表世界 
#include<stdio.h>

int dm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap(int year)
{
 return !(year % 4) && year % 100 || !(year % 400);
}

int get_days(int y, int m)
{
 if(is_leap(y) && m == 2)
 {
  return 29;
 }

 return dm[m-1];
}

int is_p_m(int m)
{
 return  (m==2||m==3||m==5||m==7||m==11);
}

int is_p_d(int d)
{
 return (d==2||d==3||d==5||d==7||d==11||d==13||d==17||d==19||d==23||d==29||d==31);
}

void get_next_pd(int* y, int* m, int* d)
{
 while(!is_p_m(*m))
 {
  (*m)++;
  *d=1;
  if(*m>12)
  {
   (*y)++;
   *m=1;
  }
 }
 int days = get_days(*y, *m);
 while(*d <= days)
 {
  if(is_p_d(*d))
  {
   return;
  }
  (*d)++;
 }
 if(*d > days)
 {
  (*m)++;
  *d=1;
  if(*m>12)
  {
   (*y)++;
   *m=1;
  }
  return get_next_pd(y, m, d);
 }
}

int main()
{
 int t;
 scanf("%d", &t);
 while(t-->0)
 {
  int y0, m0, d0, y1, m1, d1;
  scanf("%d %d %d %d %d %d", &y0, &m0, &d0, &y1, &m1, &d1);
  int ans = 0;
  int cy = y0, cm = m0, cd=d0;
  while(true)
  {
   get_next_pd(&cy, &cm, &cd);
   if(cy>y1) break;
   if(cy==y1 && cm > m1) break;
   if(cy==y1 && cm==m1 && cd>d1) break;
   ans++;
   cd++;
   //printf("%d %d %d\n",cy, cm, cd);
  }
  printf("%d\n", ans);
 }
}