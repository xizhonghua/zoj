//3184787	2013-02-28 13:31:35	 Accepted	3247	C++	0	180	花花的表世界
#include <stdio.h>
#include <string.h>

int main()
{
	int t,c;
	char s[255];
	char ss[8][1000];
	scanf("%d", &t);
	for(int tt=0;tt<t;tt++)
	{
		scanf("%d", &c);
		memset(ss, ' ', sizeof(ss));
		for(int k=0;k<c;k++)
		{
			for(int i=0;i<5;i++)
			{
				scanf("%s", s);
				if(s[0]>='A') s[0] = s[0] - 'A' + 10; else s[0] -= '0';
				if(s[1]>='A') s[1] = s[1] - 'A' + 10; else s[1] -= '0';
				int v = s[0]*16 + s[1];
				for(int j=0;j<8;j++)
				{
					ss[j][k*6+i] = ((v%2) ? '#' : ' ');
					v/=2;
				}
			}
		}

		printf("Case %d:\n\n",tt+1);

		for(int i=0;i<7;i++)
		{
			ss[i][6*c-1] = '\0';
			printf("%s\n",ss[i]);
		}

		printf("\n");

	}
}