#include<stdio.h>
int main()
{
	int a[100],k, i,m, n,j=0;
	printf("�������һ�������Ԫ�ظ���\n");
	scanf_s("%d", &m);
	printf("��������Ԫ�أ�\n");
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