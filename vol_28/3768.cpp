/*
 * 3768.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612031	2014-04-22 08:34:54	 Accepted	3768	C++0x	10	272	xxfflower
#include <iostream>
#include <cmath>
using namespace std;

#define S(x) (((x)*((x)+1))/2)

bool getD(int n, int& d)
{
	d = sqrt(n*2);
	int s = S(d);

	if (s > n) {
		d--;
		s = S(d);
	}

	return n==s;
}

void solve(int n)
{
	int d0, d1, d2;

	if(getD(n, d0))
	{
		cout<<d0<<endl;
		return;
	}

	for(int i=1;i<=d0;i++)
	{
		int s1 = S(i);
		int left = n - s1;
		if(left < 0) break;
		if(getD(left, d1))
		{
			cout<<i<<" "<<d1<<endl;
			return;
		}

		if(d1 < i) break;
	}


	for(int i=1;i<=d0;i++)
	{
		int s1 = S(i);

		for(int j=i;j<=d0;j++)
		{
			int s2 = S(j);

			int left = n - s1 - s2;

			if(left < 0) break;

			if(getD(left, d2))
			{
				cout<<i<<" "<<j<<" "<<d2<<endl;
				return;
			}

			if(d2 < j) break;
		}
	}
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		solve(n);
	}
	return 0;
}


