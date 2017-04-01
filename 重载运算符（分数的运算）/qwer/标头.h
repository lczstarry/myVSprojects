#include<iostream>
using namespace std;
class Rational
{
public:
	
	Rational(int nn = 1, int mm = 1);	      //构造函数
	Rational operator + (Rational & A);	  //加
	Rational operator - (Rational & A);	  //减
	Rational operator * (Rational & A);	  //乘
	Rational operator / (Rational & A);	  //除 
	friend bool operator >(Rational & r1, Rational &r2);
	friend bool operator <=(Rational & r1, Rational &r2);
	friend bool operator ==(Rational & r1, Rational &r2);
	friend ostream& operator <<(ostream & out, Rational &r);
	void print()const;		 //以简分数形式显示，注意约分
	void simple(); //约分
private:		
	int m;            //分母
	int n;             //分子
};
Rational::Rational(int nn , int mm )
{
	n = nn;
	m = mm;
}
Rational Rational::operator+ (Rational & A)
{
	
	Rational R;
	R.n =A.m*n + m*A.n;
	R.m = A.m*m;
	return R;
	
}
Rational Rational::operator- (Rational & A)
{
	Rational R;
	R.n = A.m*n - m*A.n;
	R.m = A.m*m;
	return R;
}
Rational Rational::operator*(Rational & A)
{
	return Rational(n*A.n, m*A.m);
}
Rational Rational::operator/(Rational & A)
{
	return Rational(n*A.m,m*A.n);
}
void Rational::print()const
{
	
	cout << n << "/" << m << endl;
}
void Rational::simple()
{
	int i,z,x;
	for (i = 2; i <= n; i++)
	{
		z = n%i;
		x = m%i;
		if (z == 0&&x == 0)
		{
			n = n / i;
			m = m / i;
			i = 1;
		}
	}
}
bool operator >(Rational & r1, Rational &r2)
{
	int M, N;
	M = r1.n*r2.m;
	N = r1.m*r2.n;
	return M > N;

}
bool operator <=(Rational & r1, Rational &r2)
{
	int M, N;
	M = r1.n*r2.m;
	N = r1.m*r2.n;
	return M <= N;
}
bool operator ==(Rational & r1, Rational &r2)
{
	int M, N;
	M = r1.n*r2.m;
	N = r1.m*r2.n;
	return M == N;
}
ostream& operator <<(ostream & out, Rational &r)
{
	r.simple();
	out << r.n << "/" << r.m ;
	return out;
}