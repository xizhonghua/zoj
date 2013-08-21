//3409593	2013-08-21 07:24:50	 Accepted	1362	C++	0	188	花花的表世界
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int m,n,c = 0,t;
	while(cin>>m>>n && m+n!=0){
		vector<int> a,b;
		for(int i=0;i<n;i++){
			cin>>t;
			a.push_back(t);
		}
		std::sort(a.begin(), a.end(), std::greater<int>());
		for(int i=0;i<2*n;i++){
			int value = n*m - i;
			if(std::count(a.begin(), a.end(), value)==0)
				b.push_back(value);
		}

		int ans = 0, j = 0;
		for(int i=0;i<n;i++)
			if(a[i]>b[j]) ans++; else j++;

		cout<<"Case "<<++c<<": "<<ans<<endl;
	}
	return 0;
}
