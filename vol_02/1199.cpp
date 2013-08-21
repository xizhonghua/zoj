//3408614	2013-08-20 08:25:13	 Accepted	1199	C++	0	188	花花的表世界
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

namespace geo {

class Vector2{
public:
	double x;
	double y;

	Vector2() { this->x = this->y = 0; }

	Vector2(const Vector2& pt){
		this->x = pt.x;
		this->y = pt.y;
	}

	Vector2(double x, double y){
		this->x = x;
		this->y = y;
	}

	double dist(const Vector2& pt){
		return std::sqrt((x - pt.x)*(x - pt.x) + (y-pt.y)*(y-pt.y));
	}

	friend istream& operator>>(istream& in, Vector2& pt){
		in>>pt.x>>pt.y;
		return cin;
	}

	friend ostream& operator<<(ostream& out, Vector2& pt){
		out<<pt.x<<" "<<pt.y;
		return out;
	}

	double normal(){
		return std::sqrt(this->x*this->x + this->y * this->y);
	}

	Vector2 normalize(){
		double n = this->normal();
		if(n != 0){
			this->x /= n;
			this->y /= n;
		}
		else{
			this->x = 0;
			this->y = 0;
		}

		return *this;
	}

	Vector2 clone(){
		return Vector2(*this);
	}

	Vector2 operator - (const Vector2& right){
		Vector2 result(this->x - right.x, this->y - right.y);
		return result;
	}

	Vector2 operator + (const Vector2& right){
		Vector2 result(this->x + right.x, this->y + right.y);
		return result;
	}

	Vector2 operator * (double s){
		return Vector2(this->x*s, this->y*s);
	}
};

class Circle{
public:
	Vector2 center;
	double r;
	Circle() { center.x = center.y = 0; r = 0; }
	Circle(const Circle& circle){
		this->center = circle.center;
		this->r = circle.r;
	}

	void swap(Circle& c){
		Circle t = c;
		c = *this;
		*this = t;
	}

	friend istream& operator>>(istream& cin, Circle& circle){
		cin>>circle.center>>circle.r;
		return cin;
	}
};

};

using namespace geo;


int main(){
	int n;
	Circle c1, c2;
	cin>>n;
	while(n--){
		cin>>c1>>c2;

		double d = c1.center.dist(c2.center);

		if(c1.r < c2.r)
			c1.swap(c2);

		if(d <= c1.r - c2.r || c1.r == c2.r){
			cout<<"Impossible."<<endl;
			continue;
		}

		double tot_len = c2.r * d / (c1.r - c2.r) + d;

		Vector2 v = (c2.center - c1.center).normalize();

		Vector2 p = c1.center + v*tot_len;

		cout<<std::fixed<<std::setprecision(2)<<p<<endl;
	}
	return 0;
}
