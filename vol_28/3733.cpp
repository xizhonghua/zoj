/*
 * 3733.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */
//3496674	2013-12-28 13:18:06	 Accepted	3733	C++	1670	272	xxfflower

#include <iostream>
#include <cmath>
using namespace std;

const double PI = acos(-1);

double R, r, H, F, S;
double h;
double min_e;

double get_s(double r2) {

	int en = 2*PI / atan(min_e/2/r2);

	double e = 0;
	while(true) {
		e = tan(2*PI/en/2)*r2*2;
		if(e>=min_e) break;
		en--;
	}

	return e*en;
}

int main(){

	while(cin>>R>>r>>H>>F>>S) {
		h = H/F;
		min_e = S/h;
		double s = 0;
		for(int i=0;i<F;i++) {
			double r2 = ((R-r)/2 * i / F)*2 + r;
			s += get_s(r2)*h;
		}
		cout<<std::fixed<<s<<endl;
	}
	return 0;
}
