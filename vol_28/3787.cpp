/*
 * 3787.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: zhonghua
 */

//3612013	2014-04-22 03:51:26	 Accepted	3787	C++0x	120	788	xxfflower

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
public:
	int id;
	int time;

	Student(int id, int time): id(id), time(time) {}
	Student(const Student& s): id(s.id), time(s.time) {}

	bool operator < (const Student& s) const
	{
		return (time < s.time);
	}
};

int main()
{
	int t,n,l;
	int HH,MM,SS;

	cin>>t;

	while(t--)
	{
		cin>>n>>l;

		vector<Student> ss;

		for(int i=0;i<n;i++)
		{
			scanf("%d:%d:%d", &HH,&MM,&SS);

			int time = HH*3600+MM*60+SS;

			Student s(i+1, time);

			ss.push_back(s);
		}

		std::sort(ss.begin(), ss.end());

		vector<int> ans;

		int open_until = -1;

		for(const auto& s : ss)
		{
			if(s.time >= open_until)
			{
				ans.push_back(s.id);
				open_until = s.time + l;
			}
		}

		std::sort(ans.begin(), ans.end());

		cout<<ans.size()<<endl;
		for(size_t i=0;i<ans.size();++i)
		{
			if(i>0) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;

	}

}
