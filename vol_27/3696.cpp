//3410526	2013-08-22 00:11:48	 Accepted	3696	C++	110	188	花花的表世界
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int T,N;
	long double l;
	cin>>T;
	while(T--){
		cin>>N>>l;
		double s = exp(-l);
		double p = s;
		for(int i=1;i<=N;i++){
			s *= l/i;
			p += s;
		}
		cout<<std::fixed<<std::setprecision(3)<<p<<endl;
	}
	return 0;
}
