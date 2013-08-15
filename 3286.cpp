//3403397	2013-08-16 03:36:35	 Accepted	3286	C++	360	7996	花花的表世界
#include <stdio.h>
#include <string.h>

#define MAXN 1000000
int f[MAXN+1];
int a[MAXN+1];
int d[1000];
int n;

int main(){
	for(int i=1;i<=MAXN;i++) f[i] = 2;
	f[1] = 1;

	for(int i=2;i<=MAXN/2;i++)
		for(int j=2*i;j<=MAXN;j+=i)
			f[j]++;
	for(int i=1;i<=MAXN;i++)
	{
		a[i] = d[f[i]];
		d[f[i]]++;
	}
	while(~scanf("%d",&n))
		printf("%d\n", a[n]);
	return 0;
}
