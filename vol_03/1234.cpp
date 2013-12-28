/*
 * 1234.cpp
 *
 *  Created on: Dec 28, 2013
 *      Author: zhonghua
 */
//3496839	2013-12-29 02:31:15	 Accepted	1234	C++	100	332	xxfflower

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

const int MAXN = 5000;
int n1[MAXN+1], p1[MAXN+1];
int c[MAXN+1];

int main() {
	int t;

	cin>>t;
	while(t--)
	{
		int n,k;

		cin>>k>>n;

		k+=8;

		for(int i=0;i<n;i++) cin>>c[i];
        int* pre = p1;
        int* now = n1;

		std::fill(pre, pre+n+1, 0);

		for(int i=1;i<=k;i++)
		{
			std::fill(now, now+n+1, INT_MAX);
			for(int j=i*2;j<=n;j++)
			{
				now[j] = now[j-1];
				if(n-j>3*(k-i))
					now[j] = std::min(now[j], pre[j-2] + (c[j-1] - c[j-2])*(c[j-1] - c[j-2]));
			}

			if(i!=k) std::swap(now, pre);
		}

		cout<<now[n]<<endl;
	}

	return 0;
}
