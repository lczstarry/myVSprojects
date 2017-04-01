#include<iostream>
#include"circle.h"
void main()
{
	Point p1(0,0);
	Point p2(2, 0);
	Circle c1(p1, 1);
	Circle c2(p2, 1);
	relation(c1, c2);
}