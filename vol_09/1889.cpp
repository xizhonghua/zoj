//3119528	2012-11-11 21:41:10	 Accepted	1889	C++	0	220	花花的表世界
#include <stdio.h>

int f[10001];

int d(int n)
{
	if(f[n]>0) return f[n];

	int s = 1;
	int c = 0;

	while(++c)
	{
		if(s % n == 0) break;
		s = (s*10 + 1) % n;
	}

	f[n] = c;

	return c;
}

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		if(n % 2 == 0 || n % 5 == 0) continue;
		printf("%d\n", d(n));
	}
}