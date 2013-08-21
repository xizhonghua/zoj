//3181569	2013-02-21 04:34:16	 Accepted	1003	C++	20	188	花花的表世界
#include <iostream>
#include <set>
#include <string.h>
using namespace std;

#define MAXN 100

int s1,s2;
bool b[MAXN+1];
bool found;
bool hold;

void solve(int s, int t)
{
	if(found) return;
	if(s==1)
	{
		if(t == 0)
		{
			hold = true;
			solve(s2, 1);
		}
		else
		{
			found = true;
			return;
		}
	}

	int g = 100;
	if(s<g) g = s;
	for(int i=2;i<=g;i++)
	{
		if(s%i==0 && !b[i])
		{
			b[i] = true;
			solve(s/i, t);
			b[i] = false;
		}
	}
}

int main()
{

	while(cin>>s1>>s2)
	{
		found = false;
		hold = false;
		memset(b, 0, sizeof(b));
		if(s1>s2)
		{
			swap(s1,s2);
		}
		solve(s1, 0);
		if(hold)
			cout<<(found ? s2 : s1)<<endl;
		else
			cout<<s2<<endl;
	}
}