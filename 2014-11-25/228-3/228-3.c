#include<stdio.h>
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
void main()
{
	int k, *pi1 = a, b[9] = { 0 }, *pi2 = b;
	scanf_s("%d", &k);
	for (; pi1 < a + k; pi1++, pi2++)
	{
		*pi2 = *pi1;
	}
	pi1++;
	for (; pi1 < a + 10; pi1++, pi2++)
	{
		*pi2 = *pi1;
	}
	pi2 = b;
	for (; pi2 < b + 9; pi2++)
	{
		printf("%d  ", *pi2);
	}
}