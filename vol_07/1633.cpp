//3410585	2013-08-22 06:15:27	 Accepted	1633	C++	40	188	花花的表世界
#include <iostream>
#include <string>
using namespace std;
const string s = "T.T^__^";

typedef long long int64;

char big_string(int64 n){
	if(n <= 7) return s[n-1];
	int64 a = 3, b = 7, c = 0;
	while(b < n){
		c = b+a;
		a = b;
		b = c;
	}
	return big_string(n-a);
}


int main(){
	int64 n;
	while(cin>>n) cout<<big_string(n)<<endl;
	return 0;
}
