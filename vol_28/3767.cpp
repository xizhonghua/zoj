// 3612008	2014-04-22 03:05:12	 Accepted	3767	C++	0	272	xxfflower
/*
 * 3767.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

#include <iostream>
using namespace std;

int main()
{
	int t,n,m,a;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		while(n--)
		{
			cin>>a;
			m-=a;
		}

		cout<<(m>=0 ? "Safe" : "Warning")<<endl;

	}
	return 0;
}



