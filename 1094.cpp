//3405230	2013-08-17 13:15:16	 Accepted	1094	C++	0	188	花花的表世界
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

struct Matrix {
	int id;
	int rows;
	int cols;
	Matrix(){}
	Matrix(int id, int rows, int cols){
		this->id = id;
		this->rows = rows;
		this->cols = cols;
	}
};

int main(){
	int n, rows, cols;
	char id;
	map<int, Matrix> M;
	cin>>n;
	int mid = 10000;
	for(int i=0;i<n;i++){
		cin>>id>>rows>>cols;
		Matrix m;
		m.id = id - 'A';
		m.rows = rows;
		m.cols = cols;
		M[m.id] = m;
	}
	string line;
	while(cin>>line){
		if(line.length() == 1){
			int id = line[0] - 'A';
			cout<<(M.count(id) ? "0" : "error")<<endl;
		}
		else{
			int ans = 0;
			stack<int> s;
			bool flag = true;
			for(size_t i=0;i<line.length()&&flag;i++)
				if(line[i] == '('){

				}else if(line[i] == ')'){
					const Matrix& r = M[s.top()]; s.pop();
					const Matrix& l = M[s.top()]; s.pop();
					if(l.cols != r.rows) {
						flag = false; break;
					}
					ans += (l.rows*l.cols*r.cols);
					Matrix nm(++mid, l.rows, r.cols);
					M[nm.id] = nm;
					s.push(nm.id);
				}else{
					int id = line[i] - 'A';
					if(!M.count(id)) {flag = false; break; }
					const Matrix& cur = M[id];
					s.push(cur.id);
				}

			if(flag)
				cout<<ans<<endl;
			else
				cout<<"error"<<endl;
		}
	}


	return 0;
}
