// 3496397	2013-12-27 15:17:58	 Accepted	1953	C++	0	272	xxfflower

/*
 * 1953.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string a,b;
	int f[101][101];
	int p[101][101];

	while(cin>>a>>b) {
		memset(f, 0, sizeof(f));
		memset(p, 0, sizeof(p));

		for(size_t i=1;i<=a.length();i++)
			for(size_t j=1;j<=b.length();j++)
			{
				if(a[i-1] == b[j-1]) {
					f[i][j] = f[i-1][j-1] + 1;
					p[i][j] = 3;
				}
				else if(f[i][j-1] > f[i-1][j])
				{
					f[i][j] = f[i][j-1];
					p[i][j] = 1;
				}
				else
				{
					f[i][j] = f[i-1][j];
					p[i][j] = 2;
				}
			}

		string sub;
		int y = a.length();
		int x = b.length();
		while(x>0 && y>0) {
			switch (p[y][x])
			{
				case 1: --x; break;
				case 2: --y; break;
				case 3: sub = a[y-1] + sub; --x; --y; break;
			}
		}

		while(!a.empty() || !b.empty())
		{
			if(sub.empty()) {
				cout<<a<<b;
				a = b = "";
			}
			else
			{
				while(a[0]!=sub[0]) { cout<<a[0]; a.erase(0,1); }
				while(b[0]!=sub[0]) { cout<<b[0]; b.erase(0,1); }
				cout<<sub[0];
				sub.erase(0,1);
				a.erase(0,1);
				b.erase(0,1);
			}
		}

		cout<<endl;
	}
	return 0;
}
