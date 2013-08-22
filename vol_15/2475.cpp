//3411028	2013-08-22 13:11:35	 Accepted	2475	C++	0	196	花花的表世界
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

bool G[102][102];
int v[102];
int m,n,a,b,e;
bool circle;

void dfs(int s){
	if(v[s]) { circle = true; return; }
	v[s] = 1;
	for(int i=0;i<n;i++)
		if(G[s][i]) dfs(i);
	v[s]=0;
}

int main(){

	while(cin>>m && m!=-1){
		memset(G,0,sizeof(G));
		memset(v,0,sizeof(v));
		n = 0;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			n = std::max(n, std::max(a,b));
			if(a==b) continue;
			--a; --b;
			G[a][b] = true;
		}
		cin>>e;
		--e;
		circle = false;
		dfs(e);
		cout<<(!circle?"Yes":"No")<<endl;
	}
	return 0;
}
