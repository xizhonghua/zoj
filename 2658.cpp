//3113909	2012-11-06 07:37:10	 Accepted	2658	C++	0	188	花花的表世界
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string A,B;
	int a[26], b[26];
	while(cin>>A>>B)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(uint i=0;i<A.length();i++)
		{
			a[A[i]-'A']++;
			b[B[i]-'A']++;
		}
		std::sort(a, a+26);
		std::sort(b, b+26);
		bool flag = true;
		for(int i=0;i<26;i++)
			if(a[i]!=b[i])
			{
				flag = false;
				break;
			}
		cout<<(flag?"YES":"NO")<<endl;
	}
}