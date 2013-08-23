//3412499	2013-08-24 05:12:31	 Accepted	3015	C++	30	188	xxfflower
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double PI = acos(-1.0);

int main(){
	double k, h, a, b;
	while(cin>>k>>h>>a>>b){
		k = -tan(k*PI/180);
		double x = 2*k*(a-h) / (k*k + 1);
		double y = k*x + 2*h - a;
		double l = sqrt((x-b)*(x-b)+y*y);
		cout<<std::fixed<<std::setprecision(2)<<l<<endl;
	}
	return 0;
}
