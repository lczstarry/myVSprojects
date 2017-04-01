#include<stdio.h>
int main()
{
	int a[100],k, i,m, n,j=0;
	printf("请输入第一个数组的元素个数\n");
	scanf_s("%d", &m);
	printf("依次输入元素：\n");
	for (i = 0; i<m; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i<m; i++)
	{
		for (j = i + 1; j<m; j++)
		{
			if (a[i] == a[j])
			{
				m--;
				for (k = j; k<m; k++)
				{
					a[k] = a[k + 1];
				}
				j--;
			}
		}
	}
	for (i = 0; i<m; i++)
		printf("%d  ", a[i]);
	return 0;
}