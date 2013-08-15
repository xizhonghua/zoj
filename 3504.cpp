//3119561	2012-11-11 22:31:19	 Accepted	3504	C++	0	180	花花的表世界
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double norm(double a, double b)
{
	return sqrt(a*a + b*b);
}

double p_norm(double* xa, double *ya, double* xb, double* yb, double p, int l)
{
	double sum = 0;
	for(int i=0;i<l;i++)
	{
		sum += pow(norm(xa[i] - xb[i], ya[i] - yb[i]), p);
	}
	return pow(sum, 1/p);
}

char* get_a_b(char* buf, double* a, double* b)
{
	bool end = false;
	char ca[257], cb[257];
	char *s = buf, *c = 0, *p;

	memset(ca, 0, sizeof(ca));
	memset(cb, 0, sizeof(cb));

	p = strstr(s, " ");
	if(p == NULL) { p = s + strlen(s); end = true; }
	c = strstr(s, ",");
	strncpy(ca, s + 1, c - s - 1);
	strncpy(cb, c + 1, p - c - 2);
	//printf("%s %s\n", ca, cb);
	s = p;

	*a = atof(ca);
	*b = atof(cb);

	return end ? NULL : p+1;
}

int main()
{
	char buf[257];
	double xa[17], xb[17], ya[17], yb[17];
	double p;
	while(gets(buf))
	{
		if(feof(stdin)) break;
		if(strlen(buf) == 0) continue;
		int l = 0;
		char* s = buf;
		while(s)
		{
			s = get_a_b(s, xa+l, ya+l);
			l++;
		}
		gets(buf);
		s = buf;
		for(int i=0;i<l;i++)
		{
			s = get_a_b(s, xb+i, yb+i);
		}
		scanf("%lf", &p);
		printf("%.16lf\n", p_norm(xa, ya, xb, yb, p, l));
	}

}