//3175797	2013-02-04 23:54:35	 Accepted	1789	C++	780	708
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

typedef set<int>::const_iterator CIT;

int main()
{
	int m,n;
	while(~scanf("%d%d",&n, &m)&&n)
	{
		set<int> as;
		vector<set<int> > groups;

		groups.resize(m);

		for(int i=0;i<m;i++)
		{
			set<int>& group = groups[i];
			int k;
			scanf("%d", &k);
			for(int j=0;j<k;j++)
			{
				int id;
				scanf("%d", &id);
				group.insert(id);
			}
		}

		as.insert(0);

		unsigned int s = as.size();

		while(true)
		{
			for(int i=0;i<m;i++)
			{
				set<int>& group = groups[i];

				for(CIT it = as.begin(); it!=as.end(); ++it)
				{
					if(group.count(*it))
					{
						for(CIT iit = group.begin(); iit!= group.end(); ++iit)
						{
							as.insert(*iit);
						}
						break;
					}
				}
			}

			if(s==as.size()) break;

			s = as.size();
		}

		printf("%d\n", s);
	}
}