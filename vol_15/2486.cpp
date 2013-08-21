//3403400	2013-08-16 03:59:33	 Accepted	2486	C++	0	188	花花的表世界
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
	double k,p;
	while(cin>>k>>p){
		int n = round(std::exp((std::log(p) / k)));
		cout<<n<<endl;
	}
	return 0;
}
