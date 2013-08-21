//3403709	2013-08-16 12:50:32	 Accepted	1450	C++	10	188	花花的表世界
#include <cstdio>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cmath>
#include <cstdlib>      // std::rand, std::srand
#include <iostream>
using namespace std;

struct Point {
	double x, y;
	Point(){
		this->x = 0;
		this->y = 0;
	}
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}
	double dist(const Point& p) const{
		return std::sqrt((this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y));
	}
};

struct Line {
	static bool IsPerpendicular(const Point& pt1, const Point& pt2, const Point& pt3){
		double yDelta_a= pt2.y - pt1.y;
		double xDelta_a= pt2.x - pt1.x;
		double yDelta_b= pt3.y - pt2.y;
		double xDelta_b= pt3.x - pt2.x;

		// checking whether the line of the two pts are vertical
		if (fabs(xDelta_a) <= 0.000000001 && fabs(yDelta_b) <= 0.000000001){
			return false;
		}

		if (fabs(yDelta_a) <= 0.0000001){
			return true;
		}
		else if (fabs(yDelta_b) <= 0.0000001){
			return true;
		}
		else if (fabs(xDelta_a)<= 0.000000001){
			return true;
		}
		else if (fabs(xDelta_b)<= 0.000000001){
			return true;
		}
		return false;
	}
};

struct Circle{
	Point center;
	double radius;
	Circle(){
		this->center = Point(0,0);
		this->radius = 0;
	}
	Circle(double x, double y, double r){
		this->center = Point(x,y);
		this->radius = r;
	}
	Circle(const Point& p, double r){
		this->center = p;
		this->radius = r;
	}
	bool contains(const Point& p) const{
		return (this->center.dist(p) <= this->radius);
	}
	static Circle Enclose(const Point& p1, const Point& p2){
		Circle c;
		c.center = Point((p1.x+p2.x)/2, (p1.y+p2.y)/2);
		c.radius = p1.dist(p2)/2;
		return c;
	}
	static Circle MakeCircle(const Point& pt1, const Point& pt2, const Point& pt3){
		Circle c;
		if (!Line::IsPerpendicular(pt1, pt2, pt3) )				return Circle::CalcCircle(pt1, pt2, pt3);
		else if (!Line::IsPerpendicular(pt1, pt3, pt2) )		return Circle::CalcCircle(pt1, pt3, pt2);
		else if (!Line::IsPerpendicular(pt2, pt1, pt3) )		return Circle::CalcCircle(pt2, pt1, pt3);
		else if (!Line::IsPerpendicular(pt2, pt3, pt1) )		return Circle::CalcCircle(pt2, pt3, pt1);
		else if (!Line::IsPerpendicular(pt3, pt2, pt1) )		return Circle::CalcCircle(pt3, pt2, pt1);
		else if (!Line::IsPerpendicular(pt3, pt1, pt2) )		return Circle::CalcCircle(pt3, pt1, pt2);
		cout<<"???"<<endl;
		//exit(-1);
		return c;
	}
	static Circle CalcCircle(const Point& pt1, const Point& pt2, const Point& pt3){
		double yDelta_a= pt2.y - pt1.y;
		double xDelta_a= pt2.x - pt1.x;
		double yDelta_b= pt3.y - pt2.y;
		double xDelta_b= pt3.x - pt2.x;

		Circle circle;

		if (fabs(xDelta_a) <= 0.000000001 && fabs(yDelta_b) <= 0.000000001){
			circle.center.x= 0.5*(pt2.x + pt3.x);
			circle.center.y= 0.5*(pt1.y + pt2.y);
			circle.radius= circle.center.dist(pt1);		// calc. radius

			return circle;
		}

		// IsPerpendicular() assure that xDelta(s) are not zero
		double aSlope=yDelta_a/xDelta_a; //
		double bSlope=yDelta_b/xDelta_b;
		if (fabs(aSlope-bSlope) <= 0.000000001){	// checking whether the given points are colinear.
			cout<<"colinear"<<endl;
			exit(-1);
			return circle;
		}

		// calc center
		circle.center.x= (aSlope*bSlope*(pt1.y - pt3.y) + bSlope*(pt1.x + pt2 .x)
			- aSlope*(pt2.x+pt3.x) )/(2* (bSlope-aSlope) );
		circle.center.y = -1*(circle.center.x - (pt1.x+pt2.x)/2)/aSlope +  (pt1.y+pt2.y)/2;

		circle.radius= circle.center.dist(pt1);		// calc. radius

		return circle;
	}
};

Circle MinDiscWith2Points(vector<Point>& P, const Point& q1, const Point& q2){
	Circle d = Circle::Enclose(q1,q2);
	int size = P.size();
	for(int i=0;i<size;i++)
		if(!d.contains(P[i])){
			d = Circle::MakeCircle(P[i], q1, q2);
		}
	return d;
}

Circle MinDiscWithPoint(vector<Point>& P, const Point& q){
	std::random_shuffle(P.begin(), P.end());
	Circle d = Circle::Enclose(q, P[0]);
	int size = P.size();
	for(int i=1;i<size;i++)
		if(!d.contains(P[i]))
		{
			vector<Point> Q;
			Q.insert(Q.begin(), P.begin(), P.begin() + i);
			d = MinDiscWith2Points(Q, P[i], q);
		}
	return d;
}

Circle MinDisc(vector<Point>& P){
	std::random_shuffle(P.begin(), P.end());
	Circle d = Circle::Enclose(P[0], P[1]);
	int size = P.size();
	for(int i=2;i<size;i++)
		if(!d.contains(P[i])){
			vector<Point> Q;
			Q.insert(Q.begin(), P.begin(), P.begin() + i);
			d = MinDiscWithPoint(Q, P[i]);
		}
	return d;
}

int main(){
	int n;
	std::srand(std::time(NULL));
	while(cin>>n){
		if(n==0) break;
		vector<Point> p;
		for(int i=0;i<n;i++){
			Point pt;
			cin>>pt.x>>pt.y;
			p.push_back(pt);
		}
		Circle d = MinDisc(p);
		printf("%.2f %.2f %.2f\n", d.center.x, d.center.y, d.radius);
	}
	return 0;
}
