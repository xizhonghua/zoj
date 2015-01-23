//3854725 2015-01-24 07:34:43 Accepted  1141  C++0x 4440  2768  xxfflower

#include <cstdio>

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node
{
  Node(int id) {
    this->id = id;
    this->total = -1;
    this->parent = nullptr;
  }
  int id;  
  int total;  
  Node* parent;
};

Node* CCA(Node* n1, Node* n2)
{
  if(n1 == n2) return n1;
  if(n1->parent == n2) return n2;
  if(n2->parent == n1) return n1;
  if(n1->parent == nullptr) return n1;
  if(n2->parent == nullptr) return n2;
  if(n1->parent == n2->parent) return n1->parent;

  unordered_set<Node*> v;
  queue<Node*> q;

  q.push(n1->parent);
  q.push(n2->parent);
  v.insert(n1->parent);
  v.insert(n2->parent);

  while(!q.empty())
  {
    auto n = q.front();
    q.pop();

    if(n->parent == nullptr) continue;

    if(v.count(n->parent)) return n->parent;

    v.insert(n->parent);
    q.push(n->parent);
  }

  return nullptr;

}

int main()
{
  int n;
  
  while(~scanf("%d", &n)) {
    map<int, Node*> m;

    for(int i=0;i<n;i++) {
      int id, cc, cid;
      scanf("%d:(%d)", &id, &cc);      
      
      if(!m.count(id)) 
        m[id] = new Node(id);
      auto parent = m[id];

      for(int i=0;i<cc;i++) {      
        scanf("%d", &cid);
        
        if(!m.count(cid)) 
          m[cid] = new Node(cid);
        
        auto child = m[cid];

        child->parent = parent;
      }      
    }

    // answer query
    map<int, int> count;
    int e;
    scanf("%d", &e);    

    while(e--) {
      int nid1, nid2;
      char c;
      scanf("%c",&c);  
      while(c!='(') scanf("%c",&c);          
      scanf("%d",&nid1);  
      scanf("%c",&c);  
      while(c!=',') scanf("%c",&c);          
      scanf("%d",&nid2);          
      scanf("%c",&c);  
      while(c!=')') scanf("%c",&c);                    
      auto cca = CCA(m[nid1], m[nid2]);
      count[cca->id]++;
    }

    for(auto kv : count)
      cout<<kv.first<<":"<<kv.second<<endl;    
  }
}