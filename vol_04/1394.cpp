//3176745	2013-02-07 09:08:02	 Accepted	1394	C++	0	188	花花的表世界
#include <iostream>
#include <string>
using namespace std;

#define PI 3.14159

int main()
{
	string s;
	double x,y,z;
	while(true)
	{
		cin>>s;
		if(s == "ENDOFINPUT") break;
		cin>>x>>y>>z;
		cin>>s;
		if(z > 180) z = 360-z;
		double d = 2*z/180.0*PI*x;
		double f = d/5;
		if( f <= y)
			cout<<"YES "<<(int)(y -f)<<endl;
		else
			cout<<"NO "<<(int)(y*5)<<endl;
	}
}