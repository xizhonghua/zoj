//3404455	2013-08-16 23:31:22	 Accepted	1503	C++	0	188	花花的表世界

#include <iostream>
using namespace std;

#define MAXG 30
#define MAXL 30
int main(){
	int ans[MAXG+1][MAXL+1];
	for(int i=0;i<=MAXG;i++) ans[i][0] = i;
	for(int i=0;i<=MAXL;i++) ans[0][i] = 0;
	for(int i=1;i<=MAXG;i++)
		for(int j=1;j<=MAXL;j++)
			ans[i][j] = ans[i-1][j] + ans[i-1][j-1]+1;
	int c,g,l;
	while(cin>>g>>l && (g || l))
		cout<<"Case "<<++c<<": "<<ans[g][l]<<endl;
	return 0;
}
