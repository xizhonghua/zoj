/*
 * 2831.cpp
 *
 *  Created on: Apr 23, 2014
 *      Author: zhonghua
 */

//3613202	2014-04-23 14:20:32	 Accepted	2831	C++0x	0	272	xxfflower

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int L=8;
const int W=8;

string d0[] =
{
	"  XXXX  ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	"  XXXX  "
};

string d1[] =
{
	"   XX   ",
	" XXXX   ",
	"   XX   ",
	"   XX   ",
	"   XX   ",
	"   XX   ",
	"   XX   ",
	" XXXXXX "
};

string d2[] =
{
	"  XXXX  ",
	" XX  XX ",
	" XX  XX ",
	"     XX ",
	"    XX  ",
	"   XX   ",
	"  XX    ",
	" XXXXXX "
};

string d3[] =
{
	"  XXXX  ",
	" X   XX ",
	"     XX ",
	"   XXX  ",
	"     XX ",
	"     XX ",
	" X   XX ",
	"  XXXX  "
};

string d4[] =
{
	"    XX  ",
	"   XXX  ",
	"   XXX  ",
	"  X XX  ",
	" X  XX  ",
	" XXXXXX ",
	"    XX  ",
	"  XXXXX "
};

string d5[] =
{
	"  XXXXX ",
	"  XX    ",
	"  XXXX  ",
	"  X  XX ",
	"     XX ",
	"     XX ",
	" X   XX ",
	"  XXXX  "
};

string d6[] =
{
	"   XXXX ",
	"  XX    ",
	" XX     ",
	" XXXXX  ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	"  XXXX  "
};

string d7[] =
{
	" XXXXXX ",
	" X   XX ",
	"     XX ",
	"    XX  ",
	"    XX  ",
	"    XX  ",
	"   XX   ",
	"   XX   "
};

string d8[] =
{
	"  XXXX  ",
	" XX  XX ",
	" XX  XX ",
	"  XXXX  ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	"  XXXX  "
};

string d9[] =
{
	"  XXXX  ",
	" XX  XX ",
	" XX  XX ",
	" XX  XX ",
	"  XXXXX ",
	"     XX ",
	"    XX  ",
	" XXXX   "
};

string dp[] =
{
	"        ",
	"   X    ",
	"   X    ",
	"   X    ",
	"XXXXXXX ",
	"   X    ",
	"   X    ",
	"   X    "
};

vector<string*> d = {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, dp};

void print(const vector<int>& ns)
{
	for(int j=0;j<L;j++)
	{
		for(const auto& n : ns)
		{
			cout<<d[n][j];
		}
		cout<<endl;
	}
}

int match(const vector<string>& input)
{
	for(int i=0;i<11;i++)
	{
		bool flag = true;
		for(int j=0;j<L;j++)
		{
			if(d[i][j].find(input[j]) == std::string::npos)
			{
				flag = false;
				break;
			}
		}
		if(flag) return i;
	}
	//???
	return 0;
}

vector<int> parse(const vector<string>& input)
{
	vector<int> results;

	int l = input[0].length();
	int i = 0;

	while(i<l)
	{
		int count=0, lx=-1;
		for(int j=0;j<L;j++)
		{
			if(input[j][i] == 'X') { count++; lx=j;}
		}
		if(count==0) { ++i; continue;}

		int w = 6;

		// +
		if(count==1 && lx == 4)
		{
			w=7;
		}

		vector<string> c;
		for(int j=0;j<L;j++)
		{
			string line = input[j].substr(i, w);
			c.push_back(line);
		}

		int digit = match(c);

		results.push_back(digit);

		i+=w;
	}

	return results;
}

int main() {

	int n;

	cin>>n;

	while(n--)
	{
		vector<string> input;
		string line;
		std::getline(cin, line);
		size_t maxL = 0;
		for(int i=0;i<L;i++)
		{
			std::getline(cin, line);
			input.push_back(line);
			maxL = std::max(maxL, line.length());
		}

		// adding spaces at the end of string to make all lines have the same length
		for(int i=0;i<L;i++)
			input[i]+= string(maxL-input[i].length()+1, ' ');

		vector<int> ds = parse(input);

		int a=0;
		int b=0;
		int* c=&a;

		for(size_t i=0;i<ds.size();i++)
		{
			if(ds[i] == 10)
			{
				c=&b;
			}
			else
			{
				*c=(*c)*10+ds[i];
			}
		}

		vector<int> result;

		int sum = a+b;

		do
		{
			result.push_back(sum%10);
			sum/=10;
		}while(sum!=0);

		std::reverse(result.begin(), result.end());

		print(result);

		if(n>0) cout<<endl;
	}
	return 0;
}
