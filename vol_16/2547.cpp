//3411634	2013-08-23 09:26:10	 Accepted	2547	C++	0	188	xxfflower
#include <iostream>
using namespace std;

typedef unsigned long long uint64;

uint64 f[31];

int main(){
	f[0] = 1;
	f[2] = 3;
	for(int i=4;i<=30;i+=2){
		f[i] = f[i-2];
		for(int j=0;j<i;j+=2)
			f[i] += 2*f[j];
	}
	int n;
	while(cin>>n && n >= 0) cout<<f[n]<<endl;
	return 0;
}
