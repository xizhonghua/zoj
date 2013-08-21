//3119562	2012-11-11 22:47:16	 Accepted	1823	C++	380	180	花花的表世界
#include <stdio.h>
#include <math.h>

int main()
{
	long long n;
	while(~scanf("%lld", &n) && n>0)
	{
		while(n)
		{
			bool found = false;
			for(long long i=2;i<sqrt(n);i++)
			{
				if(n % i == 0)
				{
					printf("%lld\n", i);
					found = true;
					n /= i;
					break;
				}
			}

			if(!found)
			{
				printf("%lld\n", n);
				break;
			}
		}

		printf("\n");
	}
}