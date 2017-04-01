#include<iostream>
#include<math.h>
using namespace std;
class Point
{
public:
	Point(){};
	Point(double  i, double  j)
	{
		x = i;
		y = j;
	}
	
	friend double dist(Point p1, Point p2);
private:
	double x;
	double y;
};

class Circle
{
public:

	Circle(Point p, double  r)
	{
		P = p;
		R = r;
	}
	friend void relation (Circle&c1, Circle&c2);
private:
	double R;
	Point P;

};
double dist(Point p1, Point p2)
{
	double _D2 = (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
	double _D3 = sqrt(_D2);
	return _D3;
}
void relation(Circle&c1, Circle&c2)
{
	double D;
	D = dist(c1.P, c2.P);
	if (D == c1.R + c2.R || D == c1.R - c2.R || D == c2.R - c1.R)
	{
		cout << "相切" << endl;
	}
	if ((D > c1.R + c2.R || D < c1.R - c2.R || D < c2.R - c1.R))
	{
		cout << "相离" << endl;
	}
	else if (D != c1.R + c2.R && D != c1.R - c2.R && D != c2.R - c1.R)
	{
		cout << "相交" << endl;
	}

}
