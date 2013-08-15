//3176812	2013-02-07 13:35:21	 Accepted	1324	C++	0	188	花花的表世界
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		vector<string> f;
		uint max_len = 0;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			if(s.length() > max_len) max_len = s.length();
			f.push_back(s);
		}

		std::sort(f.begin(), f.end());

		int c = (60-max_len)/(max_len+2) + 1;

		int r = (f.size() + (c - 1))/ c;

		for(int i=0;i<60;i++)
			cout<<"-";
		cout<<endl;

		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				uint index = i + j*r;
				if(index >= f.size()) continue;
				string s = f[index];
				cout<<s;
				if(j==c-1 || i + j*r + r >= f.size()) continue;
				for(uint k=0;k<max_len+2-s.length();k++)
					cout<<" ";
			}
			cout<<endl;
		}
	}
}