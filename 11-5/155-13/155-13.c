#include<stdio.h>
int main()
{
	int a[10][10], i, j;
	for (i = 0; i<10; i++)
	for (j = 0; j<10; j++)
		a[i][j] = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <=i; j++)
		{
			if (j == 0)
				a[i][j] = 1;
			else if (i == 0)
				break;
			else
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%4d", a[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}