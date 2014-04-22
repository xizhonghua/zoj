/*
 * 1456.CPP
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3613008	2014-04-23 04:07:54	 Accepted	1456	C++0x	50	272	xxfflower

#include <iostream>
using namespace std;

const int MAXN = 101;
const int INF = 1e8;

int main() {
	int g[MAXN][MAXN];
	int p[MAXN][MAXN];
	int t[MAXN];
	int n;

	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
				if(g[i][j]<0) g[i][j] = INF;
				p[i][j] = j;
			}
		for(int i=0;i<n;i++) cin>>t[i];

		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					int tc = g[i][k] + g[k][j] + t[k];
					if(tc < g[i][j])
					{
						g[i][j] = tc;
						p[i][j] = p[i][k];
					}
					else if(tc == g[i][j])
					{
						if(p[i][k]<p[i][j]) p[i][j]=p[i][k];
					}
				}

		int a,b;
		while(cin>>a>>b && a+b > 0)
		{
			cout<<"From "<<a<<" to "<<b<<" :"<<endl;
			cout<<"Path: "<<a;
			a--;b--;
			int pre = a;
			while(pre!=b)
			{
				cout<<"-->"<<(p[pre][b]+1);
				pre=p[pre][b];
			}
			cout<<endl;
			cout<<"Total cost : "<<g[a][b]<<endl;
			cout<<endl;
		}
	}

	return 0;
}


