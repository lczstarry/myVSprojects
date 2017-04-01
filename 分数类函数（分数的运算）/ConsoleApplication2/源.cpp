#include"БъЭЗ.h"
void main()
{
	Rational r1, r2(2,3), r3(2,3);
	r1 = r2.R_add(r3);
	r1.print();
	r1 = r2.R_sub(r3);
	r1.print();
	r1 = r2.R_mul(r3);
	r1.print();
	r1 = r2.R_div(r3);
	r1.print();
	
}