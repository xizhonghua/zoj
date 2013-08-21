//3409632	2013-08-21 08:50:38	 Accepted	1950	C++	0	188	花花的表世界
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define N 16

int main(){
	string c[N];
	double p[N][N];
	double a[N][5];
	int r[] = {2,4,8,16};

	for(int i=0;i<N;i++)
		cin>>c[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>p[i][j];
			p[i][j]/=100.0;
	}

	memset(a, 0, sizeof(a));


	for (int i = 0; i < 16; ++i) a[i][0] = p[i][i / 2 * 4 + 1 - i];
	for (int round = 1; round < 4; ++round) {
	    for (int i = 0; i < 16; ++i) {
	        for (int j = 0; j < 16; ++j) {
	            if (i / r[round] == j / r[round] && i / r[round - 1] != j / r[round - 1]) {
	                a[i][round] += a[j][round - 1] * p[i][j];
	            }
	        }
	        a[i][round] *= a[i][round - 1];
	    }
	}

	for(int i=0;i<N;i++)
	{
		cout<<c[i];
		for(size_t l=0;l<10 - c[i].length();l++) cout<<" ";
		cout<<" p="<<std::fixed<<std::setprecision(2)<<a[i][3]*100<<"%"<<endl;
	}


	return 0;
}
