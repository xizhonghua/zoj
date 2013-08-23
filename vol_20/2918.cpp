//3412456	2013-08-23 23:46:47	 Accepted	2918	C++	40	276	xxfflower
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAXN 101

double p[MAXN+1][MAXN+1];
char m[MAXN][MAXN];

int main(){
	int t,h,w;
	cin>>t;
	while(t--){
		cin>>h>>w;
		for(int i=0;i<h;i++)
			cin>>m[i];
		double ans = 0;
		for(int k=0;k<w;k++){
			double score = 0.0;
			memset(p,0,sizeof(p));
			p[0][k+1] = 1.0;
			for(int i=0;i<h;i++)
				for(int j=0;j<w;j++)
				{
					if(m[i][j] == '.')
						p[i+1][j+1] += p[i][j+1];
					else if(m[i][j] == '*'){
						p[i+2][j] 	+= p[i][j+1]/2;
						p[i+2][j+2] += p[i][j+1]/2;
					}
					else{
						int v = m[i][j] - '0';
						score += (p[i][j+1] + p[i+1][j+1]) * v;
						p[i+1][j+1] = 0;
					}
				}
			ans = std::max(ans, score);
		}

		cout<<std::fixed<<std::setprecision(6)<<ans<<endl;
	}
	return 0;
}
