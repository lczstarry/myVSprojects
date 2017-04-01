#include"标头.h"

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[4] = { 2, 3, 6, 7 };
	Set s1(a, 5), s2(b, 4);
	Set s3;
	s3 = s1-=s2;
	s3.Print();
	return 0;
}