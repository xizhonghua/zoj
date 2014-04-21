//3612009	2014-04-22 03:14:08	 Accepted	3776	C++	0	272	xxfflower
/*
* 3776.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

#include<iostream>
using namespace std;

int main()
{
	int t,n,m,w,a;

	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		a = 0;
		while(n--) { cin>>w; a+=w; }
		while(m--) { cin>>w; a-=w; }

		if(a>0) cout<<"Calem"<<endl;
		if(a<0) cout<<"Serena"<<endl;
		if(a==0) cout<<"Draw"<<endl;
	}

	return 0;
}
