//3495291	2013-12-24 03:48:23	 Accepted	1307	C++	10	272	xxfflower

/*
 * 1307.cpp
 *
 *  Created on: Dec 23, 2013
 *      Author: zhonghua
 */
#include <iostream>
using namespace std;

void fill(int x, int y, int& n1, int& n2)
{
	if(x==0||y==0) return;

	int w = x / 2;
	int h = y / 2;

	if(w*h > n2) {
		n1 = max(0, n1- (x*y - 4*n2));
		n2 = 0;
	} else {
		n2 -= w*h;
		n1 = max(0, n1 - (x*y - 4*w*h));
	}
}

int main(){

	int n[6+1];

	while(true) {
		bool flag = false;
		for(int i=1;i<=6;i++) {
			cin>>n[i];
			if(n[i]!=0) flag = true;
		}

		if(flag){
			// 6x6
			int ans = n[6];
			// 5x5
			ans += n[5];
			fill(1,11*n[5],n[1],n[2]);
			// 4x4
			ans += n[4];
			fill(2,10*n[4],n[1],n[2]);
			// 3x3
			ans += (n[3] + 3) / 4;
			n[3] %= 4;
			switch(n[3]){
				case 0: break;
				case 1:
					fill(3,4,n[1],n[2]);
					fill(2,6,n[1],n[2]);
					fill(1,3,n[1],n[2]);
					break;
				case 2: fill(3,6,n[1],n[2]); break;
				case 3: fill(3,3,n[1],n[2]); break;
			}
			// 2x2
			ans += (n[2]+8) / 9;
			n[2]%=9;
			if(n[2]!=0) {
				int y = 9-n[2];
				n[2] = 0;
				fill(1, 4*y, n[1], n[2]);
			}
			// 1x1
			ans += (n[1]+35) / 36;

			cout<<ans<<endl;
		}
		else break;
	}

	return 0;
}
