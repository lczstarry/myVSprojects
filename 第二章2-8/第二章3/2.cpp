#include"2.h"

void main()
{
	ArrayList A(5),B(5),C(5);
	for (int i = 0; i < 5; i++)
	{
		A.arrayList[i] = i;
	}
	A.one();
	display(A.arrayList, A.curLen);
	for (int i = 0; i < 5; i++)
	{
		B.arrayList[i] = i;
	}
	B.two(2);
	display(B.arrayList, B.curLen);
	for (int i = 0; i < 5; i++)
	{
		C.arrayList[i] = i;
	}
	C.three(1, 3);
	display(C.arrayList, C.curLen);
}