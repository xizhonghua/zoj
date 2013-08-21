//3404496	2013-08-17 01:46:43	 Accepted	1720	C++	0	188	花花的表世界
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int a[9];
	while(cin>>a[0]){
		bool first = true;
		for(int i=1;i<=8;i++)
			cin>>a[i];
		for(int i=0;i<=8;i++)
			if(a[i])
			{
				if(!first)
					cout<< (a[i] < 0 ? " - " : " + ");
				else
					if(a[i] < 0) cout<<"-";
				if(std::abs(a[i])!=1 || i==8) cout<<std::abs(a[i]);
				if(i!=8){ // not constant
					cout<<'x';
					if(i!=7) cout<<'^'<<8-i;
				}
				first = false;
			}
		if(first) cout<<0;
		cout<<endl;
	}
	return 0;
}
