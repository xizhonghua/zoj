//2894860 2012-05-16 16:38:48 Accepted  1108 C++ 0 200 ?????? 
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#define MAX_M 1001

struct mouse{
 int w; //weight
 int s; //speed
 int i; // index;
 int p; // prev;
 int v; // value
}m[MAX_M];

int compare(mouse a, mouse b)
{
 return a.w < b.w;
}

void output(int p){
 if(p == -1) return;
 output(m[p].p);
 printf("%d\n", m[p].i+1);
}

int main()
{
 int n=0;
 while(scanf("%d %d", &m[n].w, &m[n].s)!=EOF) 
 {
  m[n].p = -1;
  m[n].v = 0;
  m[n].i = n++;
 }
 std::sort(m, m+n, compare);
 int max_v = -1, max_p = -1;
 for(int i=1;i<n;i++)
  for(int j=0;j<i;j++)
  {
   if(m[i].w > m[j].w && m[i].s < m[j].s && m[i].v < m[j].v + 1)
   {
    m[i].v = m[j].v + 1;
    m[i].p = j;
    if(m[i].v > max_v)
    {
     max_v = m[i].v;
     max_p = i;
    }
   }
  }

 
 printf("%d\n", max_v+1);
 output(max_p);
}