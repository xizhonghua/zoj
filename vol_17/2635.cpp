//3396893	2013-08-11 13:35:20	 Accepted	2635	C++	0	188	花花的表世界
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t;
	string key,ks,c;
	cin>>t;
	while(t--)
	{
		cin>>key>>c;
		ks = key;
		int cols = key.length();
		int rows = (c.length() + cols - 1)/cols;
		int lc = c.length() % cols;
		if(lc == 0) lc = cols;
		std::sort(ks.begin(), ks.end());

		vector<int> si,ei;
		int index = 0;
		for(int i=0;i<ks.length();i++)
		{
			int col = key.find_first_of(ks[i], 0);
			int l = col < lc ? rows : rows - 1;
			si.push_back(index);
			ei.push_back(index+l);
			index += l;
		}

		for(int row = 0; row<rows; row++)
		{
			for(int i=0;i<key.length();i++)
			{
				int col = ks.find_first_of(key[i], 0);
				int index = si[col] + row;
				if(index >= ei[col]) continue;
				cout<<(char)(c[index]-'A'+'a');
			}
		}

		cout<<endl;
	}
	return 0;
}
