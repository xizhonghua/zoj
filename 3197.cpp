//2892589 2012-05-14 16:44:59 Accepted  3197 C++ 90 220 ?????? 
#include<algorithm>
#include<stdio.h>
using namespace std;

struct node{
 int s;
 int t;
}nodes[5001];

bool compare(node a, node b)
{
 if(a.s < b.s) return true;
 if(a.s == b.s) return a.t > b.t;
 return false;
}

int main()
{
 int c;
 scanf("%d", &c);
 while(c-->0){
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
   scanf("%d %d", &(nodes+i)->s, &(nodes+i)->t);
  std::sort(nodes, nodes+n, compare);
  int ans = 0;
  int c_t = 1;
  int index = 0;
  while(true)
  {
   int max_t = c_t;
   int ti = -1;
   for(int i=index;i<n;i++)
   {
    if(nodes[i].s <= c_t && nodes[i].t >= max_t)
    {
     max_t = nodes[i].t;
     ti = i;
    }
   }
   index = ti+1;
   while(nodes[index].s == nodes[ti].s) index++;
   ans++;
   c_t = max_t + 1;
   if(c_t > n) break;
  }
  printf("%d\n", ans);
 }
}