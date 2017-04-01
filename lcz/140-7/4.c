#include<stdio.h>
int main()
{
	int m, n, flag,i;
	scanf_s("%d", &m);
	flag = 1;
	for (n = 2; n < m&&flag==1; n++)
	{
		if (m%n == 0)
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		printf("该数是素数");
	}
	if (flag == 0)
	{
		printf("%d=", m);
		for (i = 2; i <=m;)
		{
			if (m%i == 0)
			{
				m = m / i;
				if (m!=1)
					printf("%d*", i);
				if (m == 1)
					printf("%d", i);
			}
			if (m%i != 0)
			{
				i++;
			}
		}
	}
	return 0;
}