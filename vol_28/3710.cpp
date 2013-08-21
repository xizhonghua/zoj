//3387647	2013-08-05 09:50:01	 Accepted	3710	C++	770	416	花花的表世界
#include <iostream>
#include <algorithm>    // std::set_intersection, std::sort
#include <vector>
#include <set>

using namespace std;


int main()
{
	int c,n,m,k,s,t;
	cin>>c;
	while(c--)
	{
		cin>>n>>m>>k;
		vector<set<int> > edges(n);
		for(int i=0;i<n;i++)
			edges[i] = set<int>();
		for(int i=0;i<m;i++)
		{
			cin>>s>>t;
			edges[s].insert(t);
			edges[t].insert(s);
		}
		int f = 0, fc = 0;
		for(int i=0;i<n;i++)
			f += edges[i].size();
		while(true)
		{
			int nf = 0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
				{
					if(edges[i].count(j)>0) continue;
					vector<int> fi(edges[i].begin(), edges[i].end());
					vector<int> fj(edges[j].begin(), edges[j].end());
					vector<int> v(fi.size()+fi.size());
					vector<int>::iterator it;
					it = std::set_intersection(fi.begin(),fi.end(),fj.begin(),fj.end(), v.begin());
					v.resize(it-v.begin());
					if((int)v.size()>=k)
					{
						edges[i].insert(j);
						edges[j].insert(i);

						fc++;
					}

				}

			for(int i=0;i<n;i++)
				nf += edges[i].size();
			if(nf==f)
				break;
			f = nf;
		}

		cout<<fc<<endl;
	}
	return 0;
}
