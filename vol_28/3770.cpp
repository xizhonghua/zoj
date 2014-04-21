/*
 * 3770.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612015	2014-04-22 07:44:20	 Accepted	3770	C++0x	90	272	xxfflower

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


class Member
{
public:
	int id;
	int date;
	int score;
	int index;

	Member(int id, int date, int score, int index):id(id),date(date),score(score), index(index){}
	Member(const Member& m):id(m.id),date(m.date),score(m.score), index(m.index){}

	bool operator < (const Member& other) const
	{
		// DEC on score
		if(this->score > other.score) return true;
		if(this->score < other.score) return false;

		// scores are equal
		if(this->date < other.date) return true;
		if(this->date > other.date) return false;

		// scores and date are equal
		return this->id < other.id;
	}
};

int main()
{
	int t,n,id,YY,MM,DD,score;
	cin>>t;
	int mc[7];

	while(t--)
	{
		vector<Member> ms;
		int pos_count = 0;

		cin>>n;

		for(int i=0;i<n;i++)
		{
			scanf("%d %d/%d/%d %d",&id, &YY, &MM, &DD, &score);
			Member m(id, YY*366+MM*31+DD, score, i);
			ms.push_back(m);
			if(m.score > 0) pos_count++;
		}

		vector<int> lvs(n);

		mc[6] = pos_count*0.03;
		mc[5] = pos_count*0.07;
		mc[4] = pos_count*0.2;
		mc[3] = pos_count*0.3;
		mc[2] = pos_count - mc[3] - mc[4] - mc[5] - mc[6];
		mc[1] = n;

		std::sort(ms.begin(), ms.end());

		int cl = 6;
		while(mc[cl]==0) cl--;

		for(auto& m : ms)
		{

			lvs[m.index] = cl;
			mc[cl]--;
			if(mc[cl]==0) cl--;
		}

		for(const auto lv : lvs)
		{
			cout<<"LV"<<lv<<endl;
		}
	}
}



