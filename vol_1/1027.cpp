//3406853	2013-08-19 03:12:19	 Accepted	1027	C++	0	228	花花的表世界
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

int c2i(char ch){
	switch(ch){
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	case '-': return 4;
	}
	return -1;
}

int S[][5] = {
		{ 5, -1, -2, -1, -3},
		{-1,  5, -3, -2, -4},
		{-2, -3,  5, -2, -2},
		{-1, -2, -2,  5, -1},
		{-3, -4, -2, -1, 0}
};

int f[102][102];

int main(){
	int T,n1,n2;
	string s1, s2;
	vector<int> v1,v2;
	cin>>T;
	while(T--){
		cin>>n1>>s1>>n2>>s2;
		memset(f,0,sizeof(f));
		f[0][0] = 0;
		v1.clear();
		v2.clear();
		for(int i=1;i<=n1;i++){
			v1.push_back(c2i(s1[i-1]));
			f[i][0] = f[i-1][0] + S[v1[i-1]][4];
		}
		for(int i=1;i<=n2;i++){
			v2.push_back(c2i(s2[i-1]));
			f[0][i] = f[0][i-1] + S[v2[i-1]][4];
		}

		for(int i=1;i<=n1;i++)
			for(int j=1;j<=n2;j++)
			{
				f[i][j] = std::max(f[i][j-1] + S[v2[j-1]][4], f[i-1][j] + S[v1[i-1]][4]);
				f[i][j] = std::max(f[i][j], f[i-1][j-1] + S[v1[i-1]][v2[j-1]]);
			}

		cout<<f[n1][n2]<<endl;
	}
	return 0;
}
