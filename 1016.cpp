//3406726	2013-08-19 00:58:38	 Accepted	1016	C++	0	188	花花的表世界
#include<iostream>
#include<vector>
using namespace std;

int main(){
	int t,n,p;
	cin>>t;
	while(t--){
		int l = 0;
		vector<char> v;
		cin>>n;

		for(int i=0;i<n;i++){
			cin>>p;
			for(int j=l;j<p;j++)
				v.push_back('(');
			v.push_back(')');
			l = p;
		}

		int rc = 0;
		for(size_t i=0;i<v.size();i++)
		{
			if(v[i] == ')') {
				int w = 1;
				for(int j=i-1;j>=0;j--)
				{
					if(v[j] == '(') {
						v[j] = '[';
						break;
					}
					if(v[j] != ')')
						w++;
				}
				if(rc != 0) cout<<" ";
				cout<<w;
				rc ++;
			}
		}
		cout<<endl;
	}
	return 0;
}
