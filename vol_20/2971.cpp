/*
 * 2971.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: zhonghua
 */

//3614057	2014-04-24 01:11:17	 Accepted	2971	C++0x	20	276	xxfflower

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
map<string, int> h;

int main()
{
	int t;

	m["zero"] 		= 0;
	m["one"] 		= 1;
	m["two"] 		= 2;
	m["three"] 		= 3;
	m["four"] 		= 4;
	m["five"]		= 5;
	m["six"] 		= 6;
	m["seven"]		= 7;
	m["eight"]		= 8;
	m["nine"]		= 9;
	m["ten"]		= 10;
	m["eleven"]		= 11;
	m["twelve"]		= 12;
	m["thirteen"]	= 13;
	m["fourteen"]	= 14;
	m["fifteen"]	= 15;
	m["sixteen"]	= 16;
	m["seventeen"]	= 17;
	m["eighteen"]	= 18;
	m["nineteen"]	= 19;
	m["twenty"]		= 20;
	m["thirty"]		= 30;
	m["forty"]		= 40;
	m["fifty"]		= 50;
	m["sixty"]		= 60;
	m["seventy"]	= 70;
	m["eighty"]		= 80;
	m["ninety"]		= 90;

	h["million"]	= 1000000;
	h["thousand"]	= 1000;

	cin>>t;

	string s;
	std::getline(cin, s);
	while(t--)
	{
		std::getline(cin, s);
		stringstream ss(s);
		vector<int> ns;
		int sum = 0;
		while(ss>>s)
		{
			if(m.count(s))
				ns.push_back(m[s]);

			if(h.count(s))
			{
				int t = h[s];
				for(auto n:ns) sum+=(n*t);
				ns.clear();
			}

			if(s=="hundred")
				for(auto& n:ns) n*=100;
		}

		for(const auto n : ns)
			sum += n;

		cout<<sum<<endl;
	}

	return 0;
}



