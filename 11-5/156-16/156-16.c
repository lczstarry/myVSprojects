#include<stdio.h>
int main()
{
	int a[3][5], i, j,m,b[5],c[3],temp,max;
	printf("�밴˳������ÿ���˶�Ӧ��3�ſγɼ�\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf_s("%d", &a[j][i]);
		}
	}
	printf("�����\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	for (j = 0; j < 5; j++)
	{
		for (i = 0,m=0; i < 3; i++)
		{
			m += a[i][j];
		}
		b[j] = m / 3;
	}
	for (j = 0; j < 3; j++)
	{
		for (i = 0,m=0; i < 5; i++)
		{
			m += a[j][i];
		}
		c[j] = m / 5;
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2 - i; j++)
		{
			if (c[j]>c[j + 1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	printf("ÿ�ſε�ƽ���ɼ�Ϊ������\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", c[i]);
	}
	for (i = 0; i < 4; i++)
	{
		max = i;
		for (j = i + 1; j < 5; j++)
		{
			if (b[i]<b[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			temp = b[i];
			b[i] = b[max];
			b[max] = temp;
		}
	}
	printf("ÿ���˵�ƽ���ɼ�Ϊ������\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", b[i]);
	}
	return 0;
}