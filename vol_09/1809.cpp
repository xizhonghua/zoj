//3410744	2013-08-22 09:38:23	 Accepted	1809	C++	0	188	花花的表世界
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct DIR {
	DIR(){}
	DIR(const string& name) {this->name = name;}
	string name;
	vector<DIR> dirs;
	vector<string> files;
};

DIR root;
DIR* cur = NULL;
stack<DIR*> parents;

void print(DIR& dir, int d){
	for(int i=0;i<d;i++)
		cout<<"|     ";
	cout<<dir.name<<endl;
	for(size_t i=0;i<dir.dirs.size();i++)
		print(dir.dirs[i], d+1);
	std::sort(dir.files.begin(), dir.files.end());
	for(size_t i=0;i<dir.files.size();i++)
	{
		for(int T=0;T<d;T++)
			cout<<"|     ";
		cout<<dir.files[i]<<endl;
	}
}

void init_dir(){
	root.name = "ROOT";
	root.dirs.clear();
	root.files.clear();
	cur = &root;
	while(!parents.empty())parents.pop();
}

int main(){
	string s;
	int c = 0;

	init_dir();
	while(cin>>s && s!="#"){
		if(s=="*"){
			if(c>0) cout<<endl;
			cout<<"DATA SET "<<++c<<":"<<endl;
			print(root, 0);
			init_dir();
		}else if(s=="]"){
			cur = parents.top();
			parents.pop();
		}else if(s[0] == 'd'){
			cur->dirs.push_back(DIR(s));
			parents.push(cur);
			cur = &(cur->dirs.back());
		}
		else if(s[0] == 'f'){
			cur->files.push_back(s);
		}
	}
	return 0;
}

