#include <iostream>
using namespace std;
class Complex                                       //定义Complex类
{
public:
	Complex(){ dReal = 0; dImag = 0; }                    //默认构造函数
	Complex(double r, double i){ dReal = r;  dImag = i; }    //重载构造函数
	friend Complex add(const Complex &c1, const Complex &c2);         
	friend Complex sub(const Complex &c1, const Complex &c2);
	friend Complex mul(const Complex &c1, const Complex &c2);
	friend Complex div(const Complex &c1, const Complex &c2);

private:
	double dReal;                                  	//实部
	double dImag;                                  	//虚部
};
Complex add(const Complex &c1, const Complex &c2)
{
	Complex c;
	c.dReal = c1.dReal + c2.dReal;
	c.dImag = c1.dImag + c2.dImag;
	return c;
}
Complex sub(const Complex &c1, const Complex &c2)
{
	return Complex(c1.dReal - c2.dReal, c1.dImag - c2.dImag);
}
Complex mul(const Complex &c1, const Complex &c2)
{
	return Complex((c1.dReal*c2.dReal - c1.dImag*c2.dImag), (c1.dReal*c2.dImag + c1.dImag*c2.dReal));
}
Complex div(const Complex &c1, const Complex &c2)
{
	return Complex((c1.dReal*c2.dReal + c1.dImag*c2.dImag) / (c2.dReal*c2.dReal + c2.dImag*c2.dImag), (c1.dImag*c2.dReal - c1.dReal*c2.dImag) / (c2.dReal*c2.dReal + c2.dImag*c2.dImag));
}


