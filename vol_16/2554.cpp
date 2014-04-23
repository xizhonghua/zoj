/*
 * 2554.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */
//3613031	2014-04-23 09:23:07	 Accepted	2554	C++0x	0	1836	xxfflower

#include <iostream>
using namespace std;

const int MAXN = 200000;

int x[MAXN],y[MAXN];

int main()
{
	int n;

	while(cin>>n && n)
	{
		for(int i=0;i<n;i++)
			cin>>x[i]>>y[i];

		int center = n/2;
		int cx = x[center];
		int cy = y[center];

		int S = 0, O = 0;

		for(int i=0;i<n;i++)
		{
			int tx = x[i];
			int ty = y[i];

			if(tx==cx || ty == cy) continue;

			if((tx > cx && ty > cy) || (tx < cx && ty < cy)) S++;
			else O++;
 		}

		cout<<S<<" "<<O<<endl;
	}

	return 0;
}



