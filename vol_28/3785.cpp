/*
 * 3785.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612046	2014-04-22 09:52:07	 Accepted	3785	C++0x	830	272	xxfflower


#include <iostream>
#include <string>
using namespace std;

const string days[7] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
const int KEY = 294;
int f[KEY+1];

int quick_pow(int n, int p)
{
	int ans = 1;

	while(p!=0)
	{
		if(p&1) ans=(ans*n)%7;
		p>>=1;
		n=(n*n)%7;
	}
	return ans;
}

int main()
{
	f[0] = 0;
	for(int i=1;i<=KEY;i++)
		f[i] = (f[i-1] + quick_pow(i,i))%7;

	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		cout<<days[f[n%KEY]]<<endl;
	}
	return 0;
}
