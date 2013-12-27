// 3496633	2013-12-28 02:09:46	 Accepted	2397	C++	20	280	xxfflower
/*
* 2397.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int t[MAXN+1];
int k[MAXN+1];

int main(){
	int n;
	while(cin>>n && n) {

		for(int i=0;i<n;i++) cin>>t[i];
		for(int i=0;i<n;i++) cin>>k[i];
		std::sort(t, t+n);
		std::sort(k, k+n);

		int* ts = t, *tf = t+n-1;
		int* ks = k, *kf = k+n-1;
		int w = 0;

		while(ts <= tf) {
			if(*tf == *kf) {
				if(*ts > *ks) {
					w++; ts++; ks++;
				}
				else {
					if(*ts < *kf) w--;
					ts++; kf--;
				}
			}
			else if(*tf > *kf) {
				w++; tf--; kf--;
			}
			else {
				w--; ts++; kf--;
			}
		}

		cout<<w*200<<endl;
	}

	return 0;
}
