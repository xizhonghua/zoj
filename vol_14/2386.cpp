//3496630	2013-12-28 01:36:03	 Accepted	2386	C++	300	4180	xxfflower

/*
 * 2386.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */



#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

const int MAXN=500000;

int a[MAXN+1];
int b[MAXN/2+1], c[MAXN/2+1];
int n;

long long sum;

void merge(int l, int mid, int r) {
	int ls = mid-l+1;
	int rs = r-(mid+1)+1;
	memcpy(b, a+l, sizeof(int)*ls);
	memcpy(c, a+mid+1, sizeof(int)*rs);
	b[ls] = INT_MAX;
	c[rs] = INT_MAX;

	int i = 0, j = 0;

	for(int k=l;k<=r;k++) {
		if(b[i]<=c[j])
			a[k] = b[i++];
		else{
			sum += ls - i;
			a[k] = c[j++];
		}
	}
}

void merge_sort(int l, int r) {
	if(l>=r) return;
	int mid = (l+r)/2;
	merge_sort(l, mid);
	merge_sort(mid+1, r);
	merge(l, mid, r);
}

int main() {
	while(cin>>n && n) {
		for(int i=0;i<n;i++) cin>>a[i];
		sum = 0;
		merge_sort(0, n-1);
		cout<<sum<<endl;
	}

	return 0;
}
