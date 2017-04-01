#include<stdio.h>
int main()
{
	int a[100], b[100], k, i, m, n, j = 0;
	printf("请输入数组的元素个数n\n");
	scanf_s("%d", &n);
	printf("依次输入元素：\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	printf("请输入移动单位m\n");
	scanf_s("%d", &m);
	for (i = 0; i < m; i++, j++)
	{
		b[j] = a[i];
	}
	for (i = 0,k=m; k< n; i++,k++)
	{
		a[i] = a[k];
	}
	for (j = 0; i < n; i++, j++)
	{
		a[i] = b[j];
	}
	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;

}