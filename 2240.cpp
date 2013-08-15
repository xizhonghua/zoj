//3176363	2013-02-06 09:37:53	 Accepted	2240	C++	0	180	花花的表世界
#include <stdio.h>
#include <string.h>

int main()
{
	char s[65537];

	while(gets(s))
	{
		int l = strlen(s);
		int i = 0;
		int last_c = -1;
		char ch;
		while(i<l)
		{
			ch = s[i];
			int c = 1;
			i++;
			while(i<l && s[i] == ch && c < 9)
			{
				c++;
				i++;
			}
			if(c!=1)
			{
				if(last_c == 1) printf("1");
				printf("%d%c", c, ch);
			}
			else if(last_c == 1)
			{
				printf("%c", ch);
				if(ch == '1')
					printf("1");
			}
			else
			{
				if(ch == '1')
					printf("1");
				printf("1%c", ch);
			}
			last_c = c;
		}
		if(last_c == 1)
			printf("1");
		printf("\n");
	}
}