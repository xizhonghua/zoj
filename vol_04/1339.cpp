//3409597	2013-08-21 07:53:12	 Accepted	1339	C++	0	188	花花的表世界
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define LEN 25

int main(){
	int n;
	while(cin>>n && n){
		vector<int> len;
		string s;
		std::getline(cin, s);
		for(int i=0;i<n;i++)
		{
			std::getline(cin, s);
			int l = 0, r = 0;
			for(int i=0;i<LEN;i++)
				if(s[i]!='X') { l=i; break; }
			for(int i=0;i<LEN;i++)
				if(s[LEN-i-1]!='X') { r=i; break; }

			if(l!=0 && r!= 0)
				len.push_back(l+r);
			else
				len.push_back(LEN);
		}

		int max_len  = *std::max_element(len.begin(), len.end());
		int ans = 0;
		for(int i=0;i<n;i++){
			ans += max_len - len[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
