//3403390	2013-08-16 02:43:18	 Accepted	3421	C++	810	304	花花的表世界
#include <iostream>
#include <iomanip>
using namespace std;

#define MAXN 10005
int t,n;
int a[MAXN],b[MAXN],c[MAXN];

inline double f(double x, int a, int b, int c){
	return a*x*x + b*x + c;
}

double F(double x){
	double v = f(x, a[0], b[0], c[0]);
	for(int i=1;i<n;i++)
		v = std::max(v, f(x, a[i], b[i], c[i]));
	return v;
}

int main(){

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i]>>b[i]>>c[i];
		double l=0.0, r=1000;
		while(r-l > 1e-12){
			double lm = (l*2 + r)/3;
			double rm = (l + r*2)/3;
			if(F(lm) < F(rm)){
				r = rm;
			}
			else{
				l = lm;
			}
		}
		cout<<std::fixed<<std::setprecision(4)<<F(l)<<endl;
	}
	return 0;
}
