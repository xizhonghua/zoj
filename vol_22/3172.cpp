/*
 * 3172.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

//3613102	2014-04-23 11:58:23	 Accepted	3172	C++0x	510	272	xxfflower

const int MAXN = 1000;

int N, M, ans;

map<int, vector<int> > m;
bool f[MAXN];

void dfs(int s, int d)
{
	for(const auto& t: m[s])
	{
		if(!f[t])
		{
			f[t]=true;
			dfs(t, d+1);
			f[t]=false;
		}
	}

	ans = max(ans, d);
}

int main(){

	while(cin>>N>>M)
	{
		ans = 0;
		m.clear();
		memset(f, 0, sizeof(f));
		for(int i=0;i<M;i++)
		{
			int s,t;
			cin>>s>>t;
			s--;
			t--;
			m[s].push_back(t);
			m[t].push_back(s);
		}

		for(int i=0;i<N;i++)
		{
			f[i] = 1;
			dfs(i, 1);
			f[i] = 0;
			if(ans == N) break;
		}

		if(ans > 7)
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
	}

	return 0;
}



