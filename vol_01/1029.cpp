/*
 * 1029.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3612929	2014-04-23 00:09:42	 Accepted	1029	C++0x	0	272	xxfflower

#include <iostream>
#include <vector>
using namespace std;

const int MAX_ROOMS = 200;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> count(MAX_ROOMS);
		int ans = 0;
		while(n--)
		{
			int ri, rj;
			cin>>ri>>rj;
			if(ri>rj) std::swap(ri,rj);
			ri=(ri-1)/2;
			rj=(rj-1)/2;
			for(int r=ri;r<=rj;r++)
			{
				count[r]++;
				ans = std::max(ans, count[r]);
			}
		}
		cout<<ans*10<<endl;
	}
	return 0;
}
