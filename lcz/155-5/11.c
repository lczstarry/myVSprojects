#include<stdio.h>
void main()
{
	int a[100], i, j, k;
	for (i = 1; i <= 100; i++)
	{
		a[i - 1] = i;
	}
	for (i = 1; i <= 100; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (a[i - 1] % j == 0)
			{
				a[i - 1] = 1;
			}
		}
	}
	for (i = 1, k = 0; i <= 100; i++)
	{
		if (a[i - 1] != 1)
		{
			printf("%d\n", a[i - 1]);
			k++;
		}
	}
	printf("共有%d个素数", k);
}