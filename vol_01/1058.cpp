/*
 * 1058.cpp
 *
 *  Created on: Dec 27, 2013
 *      Author: zhonghua
 */

// 3496642	2013-12-28 10:50:58	 Accepted	1058	C++	0	272	xxfflower

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int t,n;
	double ex[5][5];
	int d[12];
	cin>>t;
	while(t--) {
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				cin>>ex[i][j];

		while(cin>>n && n){
			double m;
			for(int i=1;i<=n;i++) { cin>>d[i]; d[i]--; }
			d[0] = d[n+1] = 0;

			cin>>m;
			for(int i=1;i<=n+1;i++)
				m = int(m * ex[d[i-1]][d[i]]*100 + 0.5) * 0.01;

			cout<<std::fixed<<std::setprecision(2)<<m<<endl;
		}

		if(t) cout<<endl;
	}
	return 0;
}
