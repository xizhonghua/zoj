//3404737	2013-08-17 09:33:55	 Accepted	2401	C++	30	228	花花的表世界
//3404723	2013-08-17 09:30:10	 Accepted	2401	C++	70	228	花花的表世界
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 202

char f[MAXN][MAXN];
char a[MAXN], b[MAXN], c[2*MAXN];

int main() {
	int n;
	cin>>n;
	for(int s=0;s<n;s++){
		memset(f, 0, sizeof(f));
		scanf("%s%s%s",a,b,c);
		int la = strlen(a), lb = strlen(b);
		for(int i=0;i<=la;i++) { if(a[i] != c[i]) break; f[i+1][0] = 1;}
		for(int i=0;i<=lb;i++) { if(b[i] != c[i]) break; f[0][i+1] = 1;}
		for(int i=1;i<=la;i++)
			for(int j=1;j<=lb;j++)
					if(((a[i-1] == c[i+j-1]) && f[i-1][j]) || ((b[j-1] == c[i+j-1]) && f[i][j-1])) f[i][j] = 1;

		cout<<"Data set "<<s+1<<": "<< (f[la][lb] ? "yes" : "no") <<endl;
	}
	return 0;
}
