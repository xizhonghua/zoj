//3404498	2013-08-17 02:32:14	 Accepted	1710	C++	0	188	花花的表世界
#include<iostream>
using namespace std;

int main(){
	double h, u, d, f;
	while((cin>>h>>u>>d>>f) && (h+u+d+f!=0)){
		int day = 0;
		double c = u * f / 100;
		double cu = u, ch = 0.0;
		bool success = true;
		while(++day){
			ch += cu;
			if(ch > h) break;
			ch -= d;
			if(ch < 0) { success = false; break;}
			cu = u - day*c;
			if(cu < 0) cu = 0;
		}

		cout<<(success?"success":"failure")<<" on day "<<day<<endl;
	}
	return 0;
}
