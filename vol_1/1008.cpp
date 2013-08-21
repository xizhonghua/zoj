//3406830	2013-08-19 02:34:05	 Accepted	1008	C++	6440	188	花花的表世界
#include <iostream>
#include <string.h>
using namespace std;

struct squre {
	int left;
	int right;
	int top;
	int bottom;
	bool operator==(const squre& o){
		return this->left == o.left
				&& this->right == o.right
				&& this->top == o.top
				&& this->bottom == o.bottom;
	}
}S[26];

int B[5][5];
int ss[25];
int sq;
int c,n,m;
bool found;

void dfs(int p){

	if(found) return;
	if(p == m) { found = true; return; }

	for(int i=0;i<sq;i++)
	{
		if(found) return;
		if(ss[i] == 0) continue;

		int x = p % n;
		int y = p / n;

		const squre& c = S[i];

		if(x>0) {
			const squre& s = S[B[y][x-1]];
			if(s.right != c.left) continue;
		}

		if(y>0){
			const squre& s = S[B[y-1][x]];
			if(s.bottom != c.top) continue;
		}

		B[y][x] = i;
		ss[i]--;
		dfs(p+1);
		if(found) return;
		ss[i]++;
	}
}

int main(){
	while(cin >> n && n){
		if(c) cout<<endl;
		m = n*n;
		sq = 0;
		memset(ss, 0, sizeof(ss));
		for(int i=0;i<m;i++) {
			cin>>S[sq].top>>S[sq].right>>S[sq].bottom>>S[sq].left;

			bool have = false;
			for(int j=0;j<sq;j++)
				if(S[j] == S[sq]){
					have = true;
					ss[j]++;
					break;
				}
			if(!have){
				ss[sq++]=1;
			}
		}
		found = false;
		dfs(0);
		cout<<"Game "<<++c<<": "<< ( found ? "Possible" : "Impossible") << endl;
	}

	return 0;
}
