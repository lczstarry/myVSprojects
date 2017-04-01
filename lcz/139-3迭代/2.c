#include<stdio.h>
int main()
{
	int m, n,a,b,i;
	scanf_s("%d%d", &m, &n);
	if (n > 0, m > 0)
	{

		if (m >= n)
		{
			a = m;
			b = n;
		}
		else
		{
			a = n;
			b = m;
		}
		for (i = 1; i > 0;)
		{
			i = a%b;
			a = b;
			b = i;
		}
	}
	if (m == 0 || n == 0)
	{
		if (n == 0)
		{
			a = m;
		}
		else
		{
			a = n;
		}
	}
	printf("%d", a);
	return 0;
}