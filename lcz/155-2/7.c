#include<stdio.h>
int main()
{
	int a[100], b[100], c[200], m, n, i, j = 0, k = 0,l=0;
	printf("�������һ�������Ԫ�ظ���\n");
	scanf_s("%d", &m);
	printf("��������Ԫ�أ����򣩣�\n");
	for (i = 0; i<m; i++)
		scanf_s("%d", &a[i]);
	printf("�������2�������Ԫ�ظ���:\n");
	scanf_s("%d", &n);
	printf("��������Ԫ�أ����򣩣�\n");
	for (i = 0; i<n; i++)
		scanf_s("%d", &b[i]);
	for (i = 0; i<m + n; i++)
	{
		if (a[j] <= b[k])
		{
			c[i] = a[j];
			j++;

		}
		else
		{
			c[i] = b[k];
			k++;

		}
		if (k >= n || j >= m)
			break;

	}
	if (j >= m)
	{
		for (i = i+1; i < m + n; i++, k++)
			c[i] = b[k];
	}
	if (k >= n)
	{
		for (i =i+1; i < m + n; i++, j++)
			c[i] = a[j];
	}
	for (i = 0; i<m + n; i++)
		printf("%d  ", c[i]);

	return 0;
}