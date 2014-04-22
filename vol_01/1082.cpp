/*
 * 1082.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3612946	2014-04-23 00:47:11	 Accepted	1082	C++0x	0	312	xxfflower

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int INF = 1e8;

int f[MAXN+1][MAXN+1];

int main()
{
	int n, c, r, t;

	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				f[i][j] = i==j ? 0 : INF;

		for(int i=0;i<n;i++)
		{
			cin>>c;
			while(c--) {
				cin>>r>>t;
				r--;
				f[i][r]=t;
			}
		}

		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k]+f[k][j];

		int start_id = -1;
		int min_t = INF;

		for(int i=0;i<n;i++)
		{
			int t = 0;
			bool disjoint=false;
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;

				if(f[i][j] >= INF)
				{
					disjoint=true;
					break;
				}

				if(f[i][j] > t)
				{
					t = f[i][j];
				}
			}
			if(!disjoint && t < min_t)
			{
				start_id = i;
				min_t = t;
			}
		}

		if(min_t == INF) cout<<"disjoint"<<endl;
		else cout<<(start_id+1)<<" "<<min_t<<endl;
	}
	return 0;
}
