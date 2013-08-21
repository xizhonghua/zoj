//3403264	2013-08-15 22:03:33	 Accepted	3708	C++	410	188	花花的表世界
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;


int main()
{
	int t,n,m,b;
	cin>>t;
	while(t--){
		map<int, set<int> > p;
		vector<int> sb, eb;
		int ans = 0;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>b;
			sb.push_back(b);
		}
		for(int i=0;i<m;i++)
		{
			cin>>b;
			eb.push_back(b);
		}
		for(int i=0;i<m;i++)
		{
			int min_bus = std::min(sb[i], eb[i]);
			int max_bus = std::max(sb[i], eb[i]);

			set<int>& s = p[min_bus];
			if(s.count(max_bus) == 0){
				s.insert(max_bus);
				ans++;
			}
		}

		cout<<std::fixed<<std::setprecision(3)<<(float)ans/n<<endl;
	}

	return 0;
}
