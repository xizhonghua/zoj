/*
 * 2954.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: zhonghua
 */
//3614036	2014-04-24 00:07:15	 Accepted	2954	C++0x	30	272	xxfflower
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int T,n,m,a,b;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		stack<int> p[4];
		for(int i=1;i<=n;i++)
			p[1].push(n-i+1);

		int result = 0;

		for(int i=1;i<=m;i++)
		{
			cin>>a>>b;

			if(result != 0) continue;

			if(p[a].empty())
			{
				result = -i;
			}
			else
			{
				int t = p[a].top();
				if(!p[b].empty() && p[b].top() < t)
					result = -i;
			}

			if(result==0)
			{
				int t = p[a].top();
				p[a].pop();
				p[b].push(t);

				if((int)p[3].size()==n) { result = i; }
			}
		}

		cout<<result<<endl;
	}
}



