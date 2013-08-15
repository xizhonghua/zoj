//3184758	2013-02-28 12:24:07	 Accepted	3464	C++	100	188	花花的表世界
#include <queue>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int c;
	int n,t,l,v;
	double s;
	cin>>c;
	while(c--)
	{
		cin>>n>>t>>l;
		priority_queue<int> q;
		for(int i=0;i<n;i++)
		{
			cin>>v;
			q.push(v);
		}
		s = 0;
		bool found = false;
		while(!q.empty())
		{
			v = q.top();
			q.pop();
			if(l > v*t)
			{
				s+=t;
				l-=v*t;
			}
			else
			{
				s+=(double)l/v;
				found = true;
				break;
			}
		}

		if(found) printf("%0.2lf\n", s); else cout<<-1<<endl;
	}
}