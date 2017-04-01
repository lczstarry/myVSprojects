#include<iostream>
using namespace std;
class Rational
{
public:
	Rational(int nn = 1, int mm = 1);	      //构造函数
	Rational  R_add(Rational & A);	  //加
	Rational  R_sub(Rational & A);	  //减
	Rational  R_mul(Rational & A);	  //乘
	Rational  R_div(Rational & A);	  //除 
	void print();		 //以简分数形式显示，注意约分
private:
	void simple();		 //约分
	int m;            //分母
	int n;             //分子
};
Rational::Rational(int nn , int mm )
{
	m = mm;
	n = nn;
}
Rational Rational::R_add(Rational & A)
{
	Rational R;
	R.m = m * A.m;
	R.n = n*A.m + m*A.n;
	return R;
}
Rational Rational::R_sub(Rational & A)
{
	Rational R;
	R.m = m * A.m;
	R.n = n*A.m -m*A.n;
	return R;
}
Rational Rational::R_mul(Rational & A)
{
	Rational R;
	R.m = m * A.m;
	R.n = n*A.m;
	return R;
}
Rational Rational::R_div(Rational & A)
{
	Rational R;
	R.m = m * A.n;
	R.n = n*A.m;
	return R;
}
void Rational::print()
{
	 simple();
	if (n == 0)
	{
		cout << n << endl;
	}
	else if (n == m)
	{
		cout << "1" << endl;
	}
	else
	cout << n<<"/"<<m<< endl;
}
void Rational::simple()
{
	int i, z, x;
	for (i = 2; i <= n; i++)
	{
		z = n%i;
		x = m%i;
		if (z == 0 && x == 0)
		{
			n = n / i;
			m = m / i;
			i = 1;
		}
	}
}

