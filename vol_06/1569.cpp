//3404419	2013-08-16 22:57:18	 Accepted	1569	C++	40	188	花花的表世界
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m,t;
	while(cin>>n>>m){
		vector<int> s(m);
		int sum = 0, ans = 0;
		for(int i=0;i<n;i++)
		{
			cin>>t;
			sum = (sum + t) % m;
			if(!sum) ans++;
			s[sum]++;
		}
		for(int i=0;i<m;i++)
			ans += s[i] * (s[i]-1)/2;
		cout<<ans<<endl;
	}
	return 0;
}
