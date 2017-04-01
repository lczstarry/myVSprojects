#include<stdio.h>
int sushu(int x)
{
	int i,m=0;
	for (i = 2; i < x; i++)
	{
		if (x%i == 0)
		{
			m = 0;
			break;
		}
		
		m = 1;
	}
	return m;
	
}
void main()
{
	int i, n;
	for (i = 1; i <= 200; i++)
	{
		n = sushu(i);
		if (n == 1)
		{
			printf("%d    ",i);
		}
	}
	
}