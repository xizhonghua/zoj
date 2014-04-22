/*
 * 1338.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3613007	2014-04-23 03:10:02	 Accepted	1338	C++0x	0	272	xxfflower

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n, l, t;
	while(cin>>l && l)
	{
		int uc = 0, ul = 0, cul = 0;
		int dc = 0, dl = 0, cdl = 0;
		n = 1;
		bool iu = false, id = false;
		while(cin>>t && t)
		{
			if(t>l)
			{
				cul++;
				if(cdl>0 && id) { dc++; dl+=cdl; }
				iu = true;
				id = false;
				cdl=0;
			}
			if(t<l)
			{
				cdl++;
				if(cul>0 && iu) { uc++; ul+=cul; }
				id = true;
				iu = false;
				cul=0;
			}

			if(t==l)
			{
				if(!id) cul++;
				if(!iu) cdl++;
			}

			l = t;

			n++;
		}

		if(cdl>0 && id) { dc++; dl+=cdl; cdl=0; }
		if(cul>0 && iu) { uc++; ul+=cul; cul=0; }

		printf("Nr values = %d:  %0.6lf %0.6lf\n", n, (uc == 0 ? 0 : (double)ul/uc) , (dc == 0 ? 0 : (double)dl/dc));
	}
	return 0;
}


