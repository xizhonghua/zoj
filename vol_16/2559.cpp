//3411659	2013-08-23 09:47:54	 Accepted	2559	C++	0	188	xxfflower
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double dist(double x, double y){
	return sqrt(x*x + y*y);
}

int main(){
	double x[3],y[3],r[3];
	while(cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]){
		double a = dist(x[0]-x[1], y[0]-y[1]);
		double b = dist(x[1]-x[2], y[1]-y[2]);
		double c = dist(x[0]-x[2], y[0]-y[2]);

		r[0] = (a-b+c)/2;
		r[1] = a-r[0];
		r[2] = c-r[0];
		cout<<std::fixed<<std::setprecision(6);
		for(int i=0;i<3;i++) cout<<r[i]<<endl;
	}
	return 0;
}
