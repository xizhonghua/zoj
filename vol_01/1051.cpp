//3410480	2013-08-21 22:19:24	 Accepted	1051	C++	0	188	花花的表世界
#include <iostream>
#include <string>
using namespace std;

#define COLS 20
#define ROWS 20
#define MAXD 16

int m[ROWS][COLS][2];
int D[MAXD];

char s[4] = {'.','!','X', '#'};

int main(){
	int N, d;
	cin>>N;
	for(int n=0;n<N;n++){
		if(n>0) cout<<endl;
		cin>>d;
		for(int i=0;i<MAXD;i++)
			cin>>D[i];

		for(int i=0;i<ROWS;i++)
			for(int j=0;j<COLS;j++)
				cin>>m[i][j][0];

		for(int t=0;t<d;t++){
			for(int i=0;i<ROWS;i++)
				for(int j=0;j<COLS;j++)
					m[i][j][1] = m[i][j][0];

			for(int i=0;i<ROWS;i++)
					for(int j=0;j<COLS;j++)
					{
						int k = m[i][j][1];
						if(i>0) k+= m[i-1][j][1];
						if(i<ROWS-1) k+=m[i+1][j][1];
						if(j>0) k+=m[i][j-1][1];
						if(j<COLS-1) k+=m[i][j+1][1];
						m[i][j][0] += D[k];
						if(m[i][j][0]<0) m[i][j][0] = 0;
						if(m[i][j][0]>3) m[i][j][0] = 3;
					}
		}

		for(int i=0;i<ROWS;i++){
			for(int j=0;j<COLS;j++)
				cout<<s[m[i][j][0]];
			cout<<endl;
		}
	}
	return 0;
}
