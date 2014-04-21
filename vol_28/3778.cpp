/*
 * 3778.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612014	2014-04-22 07:19:38	 Accepted	3778	C++0x	250	272	xxfflower

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;

		int total = 0;
		int steps = 0;
		int max_steps = 0;

		for(int i=0;i<n;i++)
		{
			cin>>steps;
			total+=steps;
			if(steps>max_steps) max_steps=steps;
		}

		int ans = std::max((total+m-1)/m, max_steps);

		cout<<ans<<endl;
	}
	return 0;
}



