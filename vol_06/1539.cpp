//3113914	2012-11-06 08:00:01	 Accepted	1539	C++	0	188	花花的表世界
#include <iostream>
#include <map>
using namespace std;

map<int, int> f;

int F(int n)
{
	if(n <= 256) return f[n];
	if(f[n] > 0) return f[n];
	int v = F(n>>1) + F((n>>1) + (n%2));
	f[n] = v;
	return v;
}

int main()
{

	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 1;
	for(int i=4;i<=256;i++)
		f[i] = f[(i>>1)] + f[(i>>1)+(i%2)];
	int n;
	while(cin>>n)
	{
		cout<<F(n)<<endl;
	}
}