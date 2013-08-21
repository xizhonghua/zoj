//3410418	2013-08-21 21:38:37	 Accepted	2376	C++	230	188	花花的表世界
#include <iostream>
using namespace std;

int main(){
	int t,l,n;
	cin>>t;
	while(t--){
		cin>>l>>n;
		int p;
		int earliest = 0, latest = 0;
		for(int i=0;i<n;i++)
		{
			cin>>p;
			earliest = std::max(earliest, p < l - p ? p : l-p);
			latest = std::max(latest, p < l - p ? l-p : p);
		}
		cout<<earliest<<" "<<latest<<endl;
	}
	return 0;
}
