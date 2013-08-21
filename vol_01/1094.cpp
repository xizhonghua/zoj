//3405295	2013-08-17 13:44:06	 Accepted	1094	C++	0	188	花花的表世界
//3405230	2013-08-17 13:15:16	 Accepted	1094	C++	0	188	花花的表世界
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

struct Matrix {
	char id;
	int rows;
	int cols;
	Matrix(){}
	Matrix(char id, int rows, int cols){
		this->id = id;
		this->rows = rows;
		this->cols = cols;
	}
};

int main(){
	int n;
	cin>>n;
	Matrix M[28];
	for(int i=0;i<n;i++){
		Matrix m;
		cin>>m.id>>m.rows>>m.cols;
		m.id -= ('A' - 1);
		M[(int)m.id] = m;
	}
	string line;
	int mid = 1000;
	while(cin>>line){
		if(line.length() == 1){
			int id = line[0] - 'A' + 1;
			cout<<(M[id].id != 0 ? "0" : "error")<<endl;
		}
		else{
			int ans = 0;
			stack<Matrix> s;
			bool flag = true;
			for(size_t i=0;i<line.length()&&flag;i++)
				if(line[i] >= 'A' && line[i] <= 'Z'){
					int id = line[i] - 'A' + 1;
					if(M[id].id == 0) {flag = false; break; }
					s.push(M[id]);
				}else if(line[i] == ')'){
					const Matrix& r = s.top(); s.pop();
					const Matrix& l = s.top(); s.pop();
					if(l.cols != r.rows) { flag = false; break; }
					ans += (l.rows*l.cols*r.cols);
					Matrix nm(++mid, l.rows, r.cols);
					s.push(nm);
				}

			if(flag)
				cout<<ans<<endl;
			else
				cout<<"error"<<endl;
		}
	}
	return 0;
}
