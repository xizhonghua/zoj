//3410637	2013-08-22 09:01:13	 Accepted	1852	C++	0	188 花花的表世界
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;


int main(){
	int a,b,s,m,n;
	while(cin>>a>>b>>s>>m>>n && a+b+s+m+n != 0){
		double x = m*a;
		double y = n*b;
		double la = atan2(y, x) * 180 / 3.1415926;
		double ls = sqrt(x*x+y*y)/s;
		cout<<std::fixed<<std::setprecision(2)<<la<<" "<<ls<<endl;
	}
	return 0;
}
