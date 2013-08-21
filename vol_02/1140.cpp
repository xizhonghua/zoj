//3409578	2013-08-21 04:40:10	 Accepted	1140	C++	630	308	花花的表世界
#include <iostream>
#include <cstring>
using namespace std;

#define MAXP 100
#define MAXN 300

int t,n,p,ns, s;
int c[MAXP+1][MAXN+1];
int v[MAXN+1];
int l[MAXN+1];

int find(int x){
	for(int i=1;i<=n;i++){
		if(v[i] || c[x][i] == 0) continue;

		v[i] = 1;

		if(l[i] == 0 || find(l[i])){
			l[i] = x;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin>>t;
	while(t--){
		memset(c, 0, sizeof(c));
		memset(l, 0, sizeof(l));
		cin>>p>>n;
		for(int i=1;i<=p;i++){
			cin>>ns;
			for(int j=0;j<ns;j++){
				cin>>s;
				c[i][s] = 1;
			}
		}

		bool found = true;

		for(int i=1;i<=p;i++){
			memset(v, 0, sizeof(v));
			if(!find(i)){
				found = false;
				break;
			}
		}

		cout<<(found ? "YES" : "NO")<<endl;
	}
	return 0;
}
