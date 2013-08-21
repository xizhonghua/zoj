//3177360	2013-02-09 03:00:01	 Accepted	1139	C++	1190	188	花花的表世界
#include <iostream>
using namespace std;

struct Rect {
	int x1, y1;
	int x2, y2;
};

int main()
{
	int n;
	while(cin>>n)
	{
		Rect* rect = new Rect[n];
		for(int i=0;i<n;i++)
			cin>>rect[i].x1>>rect[i].x2>>rect[i].y1>>rect[i].y2;

		int c = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;

				if(rect[i].x1 >= rect[j].x1 && rect[i].y1 >= rect[j].y1)
				if(rect[i].x2 <= rect[j].x2 && rect[i].y2 <= rect[j].y2)
				{
					c++;
					break;
				 }
		}
		delete [] rect;
		cout<<c<<endl;
	}
}