//3411029	2013-08-22 13:16:18	 Accepted	2475	C++	10	196	花花的表世界
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

bool G[100][100];
int m,n,a,b,e;
bool circle;

int main(){

	while(cin>>m && m!=-1){
		memset(G,0,sizeof(G));
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
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					G[i][j] |= (G[i][k]&&G[k][j]);

		circle = false;
		for(int i=0;i<n;i++)
		{
			if(!G[e][i]) continue;
			for(int j=0;j<n;j++)
				circle |= G[i][j] && G[j][i];
		}

		cout<<(!circle?"Yes":"No")<<endl;
	}
	return 0;
}
