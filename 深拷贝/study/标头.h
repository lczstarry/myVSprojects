
class Point
{
private:
	double x, y;
	char* name;
public:
	Point(char* n = NULL, double a = 0.0, double b = 0.0);
	Point(Point &p);
	~Point();
	void disp();
};
Point::Point(char * n, double a, double b)
{
	x = a; y = b;
	if (n)
	{
		name = new char[strlen(n) + 1];
		int N;
		N = strlen(n) + 1;
		strcpy_s(name,N ,n);
	}
	else
	{
		name = new char[8];
		strcpy_s(name,8, "no name");
	}
	cout << name << "constructing" << endl;
}
Point::Point(Point &p)
{
	x = p.x; y = p.y;
	if (p.name)
	{
		name = new char[strlen(p.name) + 1];
		int N;
		N = strlen(p.name) + 1;
		strcpy_s(name,N, p.name);
	}
	else
	{
		name = new char[8];
		strcpy_s(name,8, "no name");
	}
	cout << name << "copy constructing" << endl;
}
Point::~Point()
{
	cout << name << "destructing" << endl;
	delete[] name;
}
void Point::disp()
{
	cout << name << ":" << x << "," << y << endl;
}