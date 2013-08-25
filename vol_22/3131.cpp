//3413855	2013-08-25 21:35:22	 Accepted	3131	C++	110	5468	xxfflower
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

map<int,int> M;

int t2n(int h, int m, int s){
	return s + (m + h*100)*100;
}

void calc(){
	int count = 0;
	for(int h=0;h<48;h++)
		for(int m=0;m<60;m++)
			for(int s=0;s<60;s++)
			{
				int n = t2n(h,m,s);
				if(n%3==0) ++count;
				M[n] = count;
			}
}

int main(){
	int t,h1,m1,s1,h2,m2,s2;
	cin>>t;
	calc();
	while(t--){
		scanf("%2d:%2d:%2d%2d:%2d:%2d", &h1, &m1, &s1, &h2, &m2, &s2);

		int n1 = t2n(h1,m1,s1);
		int n2 = t2n(h2,m2,s2);

		if(n2 < n1) n2 += t2n(24,0,0);

		int ans = 0;

		ans = M[n2] - M[n1];

		if(n1%3==0) ans++;

		printf("%d\n", ans);

	}
	return 0;
}
