// 3496349	2013-12-27 13:26:18	 Accepted	1909	C++	0	272	xxfflower

/*
 * 1909.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int l[MAXN+1];
int f[MAXN+1];
int t,n,avg;
bool found;

void dfs(int s, int d, int cur) {

	if(found) return;

	for(int i=s;i<n&&!found;i++) {
		if(s==0 && d==0 && i==1) return;
		if(f[i]) continue;
		int sum = cur + l[i];
		if(sum > avg) continue;
		f[i] = 1;
		if(sum == avg) {
			if(d == 3) { found = true; return;}
			dfs(0, d+1, 0);
		}else {
			dfs(i+1, d, sum);
		}
		f[i] = 0;
	}
}

int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		avg = 0;
		for(int i=0;i<n;i++) {
			cin>>l[i];
			avg += l[i];
			f[i] = 0;
		}

		if(avg % 4 != 0) {
			cout<<"no"<<endl;
			continue;
		}

		avg >>= 2;

		std::sort(l, l+n);
		std::reverse(l, l+n);

		if(l[0] > avg) {
			cout<<"no"<<endl;
			continue;
		}

		found = false;
		dfs(0, 0, 0);

		if(found) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}

	return 0;
}
