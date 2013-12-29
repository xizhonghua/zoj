/*
 * 2067.cpp
 *
 *  Created on: Dec 29, 2013
 *      Author: zhonghua
 */
//497247	2013-12-30 07:02:04	 Accepted	2067	C++	40	312	xxfflower

#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

const int MAXN=100;
int n;
string map[MAXN+1];
int f[MAXN+1][MAXN+1];

int main(){

	while(cin>>n) {
		for(int i=0;i<n;i++) cin>>map[i];

		for(int i=1;i<=n;i++)
		{
			f[i][0] = 0;
			for(int j=1;j<=n;j++)
				f[i][j] = map[i-1][j-1] == '.' ? f[i][j-1] + 1 : 0;
		}

		int sum = 0;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				int m = INT_MAX;
				for(int k=i;k<=n && f[k][j];k++)
				{
					m = min(m, f[k][j]);
					sum += m;
				}
			}

		cout<<sum<<endl;
	}
	return 0;
}
