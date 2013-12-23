//3495283	2013-12-24 02:06:12	 Accepted	1093	C++	0	272	xxfflower

/*

 * 1093.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: zhonghua
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class box {
public:
	box() {	}
	box(int x, int y, int z):x(x), y(y), z(z) {}
	int x;
	int y;
	int z;
	bool can_support(const box& other) const {
		return (this->x > other.x && this->y > other.y) || (this->x > other.x && this->y > other.y);
	}

};

bool operator< (const box& b1, const box& b2)
{
	return b1.x < b2.x;
}

int main() {

	int n,c = 0;
	while(cin>>n && n) {
		vector<box> b;
		vector<int> h;
		h.reserve(n*3);

		for(int i=0;i<n;i++) {
			int x,y,z;
			cin>>x>>y>>z;
			int d1,d2,d3;
			d1 = max(max(x,y),z);
			d3 = min(min(x,y),z);
			d2 = x+y+z - d1 - d3;

			b.push_back(box(d1,d2,d3));
			b.push_back(box(d2,d3,d1));
			b.push_back(box(d1,d3,d2));
		}


		std::sort(b.begin(), b.end());


		int ans = 0;

		for(int i=0;i<3*n;i++)
		{
			int height = 0;

			for(int j=0;j<i;j++)
			{
				if(b[i].can_support(b[j])) height = max(height, h[j]);
			}

			h[i] = height + b[i].z;

			ans = max(ans, h[i]);
		}

		cout<<"Case "<<++c<<": maximum height = "<<ans<<endl;

	}

	return 0;
}
