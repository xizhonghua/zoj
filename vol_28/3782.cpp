// 3612012	2014-04-22 03:29:41	 Accepted	3782	C++	0	168	xxfflower
/*
 * 3782.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

#include <cstdio>

int calc(int n1, char op, int n2)
{
	switch(op)
	{
		case '+': return n1+n2;
		case '-': return n1-n2;
		case '*': return n1*n2;
		case '/': return n1/n2;
		case '%': return n1%n2;
	}

	return 0;
}

int main()
{
	int t,n1,n2,n3,a;
	char op1, op2;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d%*c%c%*c%d%*c%c%*c%d", &n1, &op1, &n2, &op2, &n3);

		if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/' || op2 == '%'))
			a = calc(n1, op1, calc(n2, op2, n3));
		else
			a = calc(calc(n1, op1, n2), op2, n3);

		printf("%d\n", a);
	}


	return 0;
}
