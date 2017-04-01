#include<stdio.h>
#define MAX 100
int main()
{
	int a[MAX][MAX], b[MAX][MAX], C[MAX][MAX], i, j, q, w, m, n, M,k;
	printf("注意A的列数等于B的行数\n");
	printf("请输入矩阵A的行数与列数\n");
	scanf_s("%d%d", &m, &n);
	printf("请输入矩阵B的行数与列数\n");
	scanf_s("%d%d", &q, &w);
	if (n != q)
		printf("输入错误\n");
	printf("请输入A的元素\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("请输入B的元素\n");
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < w; j++)
		{
			scanf_s("%d", &b[i][j]);
		}
	}
	printf("整理A:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("整理B:\n");
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < w; j++)
			printf("%5d", b[i][j]);
		printf("\n");
	}
	M = q;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < w; j++)
		{
			C[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < w; j++)
		{
			for (k = 0; k < M; k++)
				C[i][j] += a[i][k] * b[k][j];
		}
	}
	printf("乘积为\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%5d", C[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}
	
