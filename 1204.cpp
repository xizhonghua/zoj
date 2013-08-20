//3409580	2007-04-28 11:06:03	 Accepted	1204	C++	550	7548	花花的表世界
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int n;
vector<int> a,path;
vector<vector<int> > ans;

void dfs(int pos, int sum){
	if(pos == n || sum > a.back()) return;

	if(std::binary_search(a.begin() + pos, a.end(), sum)){
		vector<int> eq = path;
		eq.push_back(sum);
		ans.push_back(eq);
	}

	path.push_back(a[pos]);
	dfs(pos+1, sum + a[pos]);
	path.pop_back();
	dfs(pos+1, sum);
}

int comp(const vector<int>& path1, const vector<int>& path2){
	if(path1.size() == path2.size()){
		return path1 < path2;
	}else {
		return path1.size() < path2.size();
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		a.resize(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		std::sort(a.begin(), a.end());

		ans.clear();
		path.clear();
		dfs(0,0);

		std::sort(ans.begin(), ans.end(), comp);

		if(ans.empty()){
			cout<<"Can't find any equations."<<endl;
		}else{
			for(size_t i=0;i<ans.size();i++){
				const vector<int>& path = ans[i];
				if(i!=0 && ans[i] == ans[i-1]) continue;
				cout<<path.front();
				for(size_t j=1;j<path.size()-1;j++)
					cout<<"+"<<path[j];
				cout<<"="<<path.back()<<endl;
			}
		}

		cout<<endl;
	}

	return 0;
}
