#include<iostream>
#include"БъЭЗ.h"

using namespace std;
void main()
{
	Rational r1, r2(4,5), r3(3,4);
	r1 = r2 + r3;
	r1.simple();
	r1.print() ;

	r1 = r2 - r3;
	r1.simple();
	r1.print();

	r1 = r2*r3;
	r1.simple();
	r1.print();

	r1 = r2 / r3;
	r1.simple();
	r1.print();

	
}
