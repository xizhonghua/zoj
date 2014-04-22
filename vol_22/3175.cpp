/*
 * 3175.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612032	2014-04-22 09:23:17	 Accepted	3175	C++0x	20	272	xxfflower

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	long long n,a;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a = 0;
		int k=sqrt(n);
		for(int i=1;i<=k;i++)
			a += n/i;
		a*=2;
		a-=(k*k+n);
		cout<<a<<endl;
	}
	return 0;

}
