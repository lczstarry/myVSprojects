#include<stdio.h>
#define MAX 100
int main()
{
	int a[MAX][MAX], m, n, i, j, max, maxj, k, flag;
	printf("输入行数 列数:\n");
	scanf_s("%d%d", &m, &n);
	printf("输入%d个数:\n", m*n);
	for (i = 0; i<m; i++)
	for (j = 0; j<n; j++)
		scanf_s("%d", &a[i][j]);
	printf("整理:\n");
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	for (i = 0; i<m; i++)
	{
		max = a[0][0];
		maxj = 0;
		for (j = 0; j < n; j++)
		{
			if (a[i][j]>max)
			{
				max = a[i][j];
				maxj = j;
			}
			flag = 1;
			for (k = 0; k < n; k++)
			{
				if (a[k][maxj] < max)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
		{
			printf("数组有鞍点:a[%d][%d]=%d\n", i , maxj , max);
			break;
		}
	}
	if (!flag)
		printf("数组没有鞍点!\n");
	return 0;
}