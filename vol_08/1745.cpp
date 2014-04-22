/*
 * 1745.cpp
 *
 *  Created on: Apr 22, 2014
 *      Author: zhonghua
 */

//3613011	2014-04-23 06:19:59	 Accepted	1745	C++0x	0	272	xxfflower
#include <iostream>
using namespace std;

int main()
{
	int c, l, n;
	int T = 0;
	while(cin>>c && c!=5280)
	{
		if(T++>0) cout<<endl;

		l = 0;

		while(cin>>n)
		{
			cout<<"Moving from "<<l<<" to "<<n<<": ";

			if(n==c) {
				cout<<"found it!"<<endl;
				break;
			}
			else if(abs(n-c) == abs(l-c)) cout<<"same."<<endl;
			else if(abs(n-c) > abs(l-c)) cout<<"colder."<<endl;
			else cout<<"warmer."<<endl;

			l=n;
		}
	}
	return 0;
}



