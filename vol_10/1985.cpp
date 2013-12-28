//3496686   2013-12-28 14:13:06  Accepted   1985    C++ 130 2616    xxfflower

/*
 * 1985.cpp
 *
 *  Created on: Dec 28, 2013
 *      Author: zhonghua
 */

#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int64;

const int MAXN = 100000;
int64 h[MAXN+2], l[MAXN+2], r[MAXN+2];

int main() {
	int n;
	while(cin>>n && n) {
		for(int i=1;i<=n;i++) {
			cin>>h[i];
			l[i] = r[i] = i;
		}

		h[0] = h[n+1] = -1;

		for(int i=1;i<=n;i++)
			while(h[l[i]-1]>=h[i])
				l[i] = l[l[i]-1];

		for(int i=n;i>0;i--)
			while(h[r[i]+1] >= h[i])
				r[i] = r[r[i]+1];

		int64 sum = 0;

		for(int i=1;i<=n;i++)
			sum = max(sum, h[i]*(r[i]-l[i]+1));

		cout<<sum<<endl;
	}
	return 0;
}
