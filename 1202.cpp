//3184690	2013-02-28 09:42:59	 Accepted	1202	C++	0	188	花花的表世界
#include <iostream>
#include <string.h>
using namespace std;

typedef long long int64;

int b[13];
int d;
long long s;


int64 perm(int n)
{
	int64 p = 1;
	for(int i=2;i<=n;i++)
		p*=i;
	return p;
}

long long comb(int m, int n)
{
	double c = 1;
	for(int i=0;i<m-n;i++)
	{
		c = c*(m-i)/(i+1);
	}
	return c;
}

int main()
{
	int n,t;
	while(cin>>n)
	{
		d = 0;
		memset(b, 0, sizeof(b));
		for(int i=0;i<n;i++)
		{
			cin>>t;
			d+=t;
			b[t]++;
		}
		s = 1;
		for(int i=1;i<=12;i++)
		{
			if(!b[i]) continue;

			for(int j=0;j<b[i];j++)
			{
				s*=comb(d, i);
				d-=i;
			}
			s/=perm(b[i]);
		}
		cout<<s<<endl;
	}
}