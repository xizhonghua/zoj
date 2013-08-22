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

	bool contains(const Vector2& pt){
		return this->center.dist(pt) <= this->r;
	}

	bool contains(double x, double y){
		return this->contains(Vector2(x,y));
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
