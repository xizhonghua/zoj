//3411774	2013-08-23 12:37:39	 Accepted	2876	C++	1610	716	xxfflower
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		set<string> prefix;
		vector<string> list;
		list.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>list[i];
			prefix.insert(list[i]);
		}
		bool OK = true;
		for(int i=0;i<n && OK;i++){
			string t = "";
			const string& s = list[i];
			for(size_t j=0;j<s.length();j++)
			{
				t += s[j];
				if(prefix.count(t) && t!=s) { OK = false; break;}
			}
		}
		cout<<(OK?"YES":"NO")<<endl;
	}
	return 0;
}
