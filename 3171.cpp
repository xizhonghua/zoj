//3119624	2012-11-12 01:20:21	 Accepted	3171	C++	0	188	花花的表世界

#include <stdio.h>
#include <string.h>

char str[10001];

int main()
{
	while(gets(str))
	{
		long long ss = 0, se = 0, sv = 0, see = 0, sn = 0;
		for(int i=0;i<strlen(str);i++)
		{
			char ch = str[i];
			if(ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
			if(ch == 's')
				ss ++;
			else if(ch == 'e')
			{
				se+=ss;
				see+=sv;
			}else if(ch == 'v')
			{
				sv+=se;
			}
			else if(ch == 'n')
			{
				sn += see;
			}
		}
		printf("%lld\n", sn);
	}
}