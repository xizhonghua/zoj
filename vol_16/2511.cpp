/*
 * 2511.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//3613012	2014-04-23 06:42:49	 Accepted	2511	C++0x	320	272	xxfflower

class Node
{
public:
	Node(double s, int index):s(s), index(index){}
	Node(const Node& n):s(n.s), index(n.index){}
	double s;
	int index;

	bool operator < (const Node& n) const
	{
		if(n.s == this->s) return this->index < n.index;

		return n.s < this->s;
	}
};

int main(){
	int n,m,k;
	double s;
	while(cin>>n>>m>>k)
	{
		vector<Node> ns;
		for(int i=0;i<m;i++)
		{
			Node node(0,i);
			ns.push_back(node);
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>s;
				ns[j].s += s;
			}
		}

		std::sort(ns.begin(), ns.end());

		vector<int> ans;

		for(int i=0;i<k;i++) ans.push_back(ns[i].index+1);

		std::sort(ans.begin(), ans.end(), std::greater<int>());

		for(int i=0;i<k;i++)
		{
			if(i!=0) cout<<" ";
			cout<<ans[i];
		}

		cout<<endl;
	}
	return 0;
}



