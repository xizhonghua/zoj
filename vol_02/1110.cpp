/*
 * 1110.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */
//3613023	2014-04-23 09:11:51	 Accepted	1110	C++0x	0	272	xxfflower

#include <iostream>
using namespace std;

const int D = 12;

int check(int diff)
{
	return diff == 0 || diff == 1;
}

int main()
{
	int s,p,y,S,P,Y,J;

	while(cin>>s>>p>>y>>J)
	{
		Y=(D+J-p-y)/2;
		S=y+Y;
		P=p+Y;

		for(int Y_R=Y-2;Y_R<=Y+2;Y_R++)
		{
			if(Y_R<0) continue;
			for(int S_R=S-2;S_R<=S+2;S_R++)
			{
				if(S_R<0) continue;
				for(int P_R=P-2;P_R<=P+2;P_R++)
				{
					if(P_R<0) continue;

					if(S_R+P_R+Y_R == D+J)
					{
						if(!check(S_R - P_R - s)) continue;
						if(!check(S_R - Y_R - y)) continue;
						if(!check(P_R - Y_R - p)) continue;

						cout<<S_R<<" "<<P_R<<" "<<Y_R<<endl;
					}
				}
			}
		}
	}
	return 0;
}



