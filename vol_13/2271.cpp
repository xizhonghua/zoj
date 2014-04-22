/*
 * 2271.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3613009	2014-04-23 05:00:24	 Accepted	2271	C++0x	70	436	xxfflower

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN=100;

double p[2][MAXN+2][MAXN+2];
int n;

void clear(int d)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			p[d][i][j]=0;
}

int main()
{
	while(cin>>n)
	{
		double ans = 0.0;
		int d=0;
		int k=n/2;

		clear(d);

		p[d][k][k] = 1.0;

		for(int D=0;D<n;D++)
		{
			int c=1-d;
			clear(c);
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					int count = 0;

					if(i>0) 	count++;
					if(i<n-1) 	count++;
					if(j>0) 	count++;
					if(j<n-1) 	count++;

					double pp = p[d][i][j] / count;

					if(i<n-1) 	p[c][i+1][j]+=pp;
					if(j<n-1) 	p[c][i][j+1]+=pp;
					if(i>0) 	p[c][i-1][j]+=pp;
					if(j>0)		p[c][i][j-1]+=pp;
				}

			ans += p[c][k][D];
			p[c][k][D] = 0;

			d=1-d;
		}

		cout<<std::fixed<<std::setprecision(4)<<ans<<endl;
	}
	return 0;
}


