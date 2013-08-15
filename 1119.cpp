//2913596 2012-06-07 13:19:18 Accepted  1119 C++ 0 1160 花花的表世界 
#include<stdio.h>
#include<memory.h>
#include<set>

using namespace std;

#define MAXN 1001

bool c[MAXN][MAXN];
bool n[MAXN];
set<int> nodes;

void link(int s, int d)
{
 n[s] = true;
 for(set<int>::iterator it = nodes.begin(); it!= nodes.end(); ++it)
  if(c[s][*it] && *it != d && !n[*it]) link(*it, d);  
}

int main()
{
 int a, b, t = 0, sn, ans;
  
 while(~scanf("%d", &a))
 {
  if(a == 0) break;
  memset(c, 0, sizeof(c));
  nodes.clear();

  if(t>0) printf("\n");

  scanf("%d", &b);  
  c[a][b] = c[b][a] = true;
  nodes.insert(a);
  nodes.insert(b);  
  while(~scanf("%d", &a))
  {
   if(a==0) break;   
   scanf("%d", &b);
   c[a][b] = c[b][a] = true;
   nodes.insert(a);
   nodes.insert(b); 
  }

  ans = 0;
  
  printf("Network #%d\n", ++t);

  for(set<int>::iterator itd = nodes.begin(); itd != nodes.end(); ++itd)
  {
   int node_down = *itd;
   memset(n, 0, sizeof(n));   
   sn = 0;
   for(set<int>::iterator it1 = nodes.begin(); it1 != nodes.end(); ++it1)
   {
    int node1 = *it1;
    if(node1 == node_down || n[node1]) continue;
    link(node1, node_down);
    sn++;
   }

   if(sn != 1)
   {
    printf("  SPF node %d leaves %d subnets\n", node_down, sn);
    ans++;
   }
  }

  if(ans == 0)
   printf("  No SPF nodes\n");

  
 }

 return 0;
}