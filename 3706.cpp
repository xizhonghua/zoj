//3403309	2013-08-15 22:51:02	 Accepted	3706	C++	20	188	花花的表世界
#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

void count2(set<int>&s, int a, int b)
{
	s.insert(abs(a+b));
	s.insert(abs(a-b));
}

int count(int a, int b, int c)
{
	set<int> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);

	count2(s,a,b);
	count2(s,b,c);
	count2(s,a,c);

	s.insert(abs(a+b+c));
	s.insert(abs(a+b-c));
	s.insert(abs(a-b+c));
	s.insert(abs(a-b-c));

	s.erase(0);

	return s.size();
}

int main()
{
	int t,x,y;
	cin>>t;
	while(t--){
		int ans = 0;
		cin>>x>>y;

		for(int i=1;i<=x/2;i++)
		{
			int a = i, b = x - a, c = y;
			int w = count(a,b,c);
			if(w>ans) ans = w;
		}

		for(int i=1;i<=y/2;i++)
		{
			int a = i, b = y - a, c = x;
			int w = count(a,b,c);
			if(w>ans) ans = w;
		}

		cout<<ans<<endl;
	}
	return 0;
}
