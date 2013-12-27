/*
 * 3496402	2013-12-27 15:35:15	 Accepted	2277	C++	720	272	xxfflower
 * 2277.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	while(cin>>n) {
		int b = n*log10(n);
		int a = pow(10, n*log10(n) - b);
		cout<<a<<endl;
	}
	return 0;
}
