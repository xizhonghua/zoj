//3408694	2013-08-20 09:47:15	 Accepted	1107	C++	50	268	花花的表世界
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAXN 100
#define UNVISITED -1

int map[MAXN+1][MAXN+1];
int f[MAXN+1][MAXN+1];
int n,k;

int search(int x, int y){
	if(f[y][x] != UNVISITED) return f[y][x];
	int ans = f[y][x] = map[y][x];
	for(int i=-k;i<=k;i++){
		if(i==0) continue;
		int tx = x+i, ty = y+i;
		if(tx >=0 && tx < n && map[y][tx] > map[y][x])
			ans = std::max(ans, map[y][x] + search(tx,y));
		if(ty >=0 && ty < n && map[ty][x] > map[y][x])
			ans = std::max(ans, map[y][x] + search(x,ty));
	}
	f[y][x] = ans;
	return ans;
}

int main(){

	while(cin>>n>>k && n+k!=-2){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>map[i][j];
				f[i][j] = UNVISITED;
			}
		int ans = search(0,0);
		cout<<ans<<endl;
	}

	return 0;
}
