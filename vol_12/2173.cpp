//3411551	2013-08-23 08:29:36	 Accepted	2173	C++	0	188	xxfflower
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int m;
	while(cin>>m && m){
		int w,h;
		int wl = m, lh = 0, th = 0, max_width = 0;
		while(cin>>w>>h && w+h>0){
			if(wl >= w){
				wl -= w;
				lh = std::max(lh, h);
			}else{
				th += lh;
				wl = m - w;
				lh = h;
			}
			max_width = std::max(max_width, m-wl);
		}

		th += lh;

		cout<<max_width<<" x "<<th<<endl;
	}
	return 0;
}
