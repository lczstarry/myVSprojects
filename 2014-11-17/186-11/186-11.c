#include<stdio.h>
int a[5][4];
void b(int a[5][4])
{
	int i,j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}

void c(int a[5][4])
{
	int i,  j;
	int x;
	for (i = 0; i < 5; i++)
	{
		x = 0;
		for (j = 0; j < 4; j++)
		{
			if (a[i][j] < 60)
				++x;
		}
		printf("第%d同学不及格课程数为%d\n", i + 1, x);
	}
}
void d(int a[5][4])
{
	int i,  j;
	int x;
	float n;
	for (j = 0; j < 4; j++)
	{

		{
			x = 0;
			for (i = 0; i < 5; i++)
			{
				if (a[i][j] >= 60)
					++x;
			}
			n = x / 5.0;
			printf("第%d课程及格率为%.2f\n", j + 1, n);
		}
	}

}
void e(int a[5][4])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	b(a);
	c(a);
	d(a);
	e(a);
	return 0;
}
