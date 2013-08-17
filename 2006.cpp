//3404543	2013-08-17 08:09:59	 Accepted	2006	C++	80	188	花花的表世界
#include <iostream>
#include <string>
using namespace std;

bool comp(const string& s, int l, int p, int q){
	int i = 0;
	while(i<l && s[p+i] == s[q+i]) i++;
	return (i==l) ? false : s[p+i] < s[q+i];
}

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int l = s.length();
		s += s;
		int p = 0;
		for(int i=0;i<l;i++)
			if (comp(s,l, i, p))
				p = i;
		cout<<p+1<<endl;
	}
	return 0;
}
