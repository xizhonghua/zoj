//3412445	2013-08-23 23:19:26	 Accepted	2994	C++	10	188	xxfflower
#include<iostream>
using namespace std;

#define MAXN 50

typedef unsigned long long uint64;

uint64 f[MAXN] = {1, 1};
uint64 g[MAXN] = {0, 1};
uint64 h[MAXN] = {0, 1};

int main(){

	for(int i=2;i<MAXN;i++)
	{
		f[i] = f[i-1] + f[i-2] + g[i-1] + 2*h[i-1];
		g[i] = f[i-1] + g[i-2];
		h[i] = f[i-1] + h[i-1];
	}

	int N,w;
	cin>>N;

	for(int C=1;C<=N;C++){
		cin>>w;
		cout<<C<<" "<<f[w]<<endl;
	}

	return 0;
}
