//3413882	2013-08-25 22:22:55	 Accepted	3106	C++	0	188	xxfflower
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct REC {
	int id, A, SH, CH, R;
	void read(istringstream& ss, bool readR = false) {
		ss>>id>>A>>SH>>CH;
		if(readR) ss>>R;
	}
	int dis(const REC& r){
		return abs(A-r.A) + abs(SH-r.SH) + abs(CH-r.CH);
	}
};

int main(){
	string line;
	vector<REC> records;
	while(std::getline(std::cin, line) && line != "") {
		istringstream ss(line);
		REC r;
		r.read(ss,true);
		records.push_back(r);
	}

	int k;
	while(cin>>k){
		std::getline(std::cin, line);
		while(std::getline(std::cin, line) && line != "") {
			istringstream ss(line);
			REC r;
			r.read(ss);
			vector<pair<int,int> > p;
			for(vector<REC>::const_iterator it = records.begin(); it != records.end(); ++it)
				p.push_back(std::make_pair(r.dis(*it), it-records.begin()));
			std::sort(p.begin(), p.end());
			int tr = 0;
			for(int i=0;i<k;i++)
			{
				const REC& hr = records[p[i].second];
				if(hr.R == 1) tr++;
			}
			cout<<r.id<<" "<<(tr>k/2 ? 1 : 0)<<endl;
		}
	}
	return 0;
}
