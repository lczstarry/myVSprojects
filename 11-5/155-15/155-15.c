#include<stdio.h>
#define MAX 100
int main()
{
	int a[MAX][MAX], b[MAX][MAX], C[MAX][MAX], i, j, q, w, m, n, M,k;
	printf("ע��A����������B������\n");
	printf("���������A������������\n");
	scanf_s("%d%d", &m, &n);
	printf("���������B������������\n");
	scanf_s("%d%d", &q, &w);
	if (n != q)
		printf("�������\n");
	printf("������A��Ԫ��\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("������B��Ԫ��\n");
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < w; j++)
		{
			scanf_s("%d", &b[i][j]);
		}
	}
	printf("����A:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("����B:\n");
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
	printf("�˻�Ϊ\n");
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
	
