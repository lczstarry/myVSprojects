#include<stdio.h>
int main()
{
	int m, n,a,b,i,j,k;
	k = 0;
	scanf_s("%d%d", &m, &n);
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
	for (i = b; i <= a; i++)
	{
		for (j = 2; j <= i - 1; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d\n", i);
			k = k + 1;
		}
		
	}
	printf("Ò»¹²%d¸ö", k);
	return 0;

}