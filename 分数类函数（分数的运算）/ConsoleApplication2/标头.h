#include<iostream>
using namespace std;
class Rational
{
public:
	Rational(int nn = 1, int mm = 1);	      //���캯��
	Rational  R_add(Rational & A);	  //��
	Rational  R_sub(Rational & A);	  //��
	Rational  R_mul(Rational & A);	  //��
	Rational  R_div(Rational & A);	  //�� 
	void print();		 //�Լ������ʽ��ʾ��ע��Լ��
private:
	void simple();		 //Լ��
	int m;            //��ĸ
	int n;             //����
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

