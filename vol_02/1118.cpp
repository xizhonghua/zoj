/*
 * 1118.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3613004	2014-04-23 02:28:51	 Accepted	1118	C++0x	0	272	xxfflower
#include <iostream>
#include <map>
#include <list>
using namespace std;

typedef long long ll;

int n;
ll s, g;
map<ll, list<ll> > m;

bool read_cfg(ll& c)
{
	c = 0;
	int t = 0;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t<0) return false;
		c = c*10 + t;
	}
	return true;
}

bool dfs(ll c)
{
	if(c==g) return true;

	for(const auto& p : m[c])
	{
		if(dfs(p)) return true;
	}

	return false;
}

int main()
{
	int c = 0;
	while(cin>>n && n)
	{
		ll t1, t2;

		read_cfg(s); read_cfg(g);

		m.clear();

		while(true)
		{
			if(read_cfg(t1)) read_cfg(t2);
			else break;
			m[t1].push_back(t2);
		}

		cout<<"Maze #"<<(++c)<<" "<<(dfs(s) ? "can" : "cannot")<<" be travelled"<<endl;
	}
	return 0;
}
