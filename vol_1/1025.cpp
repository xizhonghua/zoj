//3406774	2013-08-19 01:30:12	 Accepted	1025	C++	10	188	花花的表世界
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stick{
	int l;
	int w;
	stick(){}
	stick(int l, int w){
		this->l = l;
		this->w = w;
	}
	bool operator<(const stick& o) const
	{
		if(this->l == o.l)
			return this->w < o.w;

		return this->l < o.l;
	}
	bool operator==(const stick& o) const
	{
		return this->l == o.l && this->w == o.w;
	}
};

int main(){
	vector<stick> v;
	vector<stick> flow;
	int t,n;
	cin>>t;
	while(t--){
		v.clear();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			stick s;
			cin>>s.l>>s.w;
			v.push_back(s);
		}

		std::sort(v.begin(), v.end());

		flow.clear();

		for(int i=0;i<n;i++){
			const stick& s = v[i];
			bool processed = false;
			for(size_t p=0;p<flow.size();p++)
			{
				if(s < flow[p]) { processed = true; break; }
				if(s == flow[p]) { processed = true; break; }
				if(s.w >= flow[p].w) {
					flow[p] = s; processed = true; break;
				}
			}
			if(!processed)
				flow.push_back(s);
		}

		cout<<flow.size()<<endl;

	}

	return 0;
}
