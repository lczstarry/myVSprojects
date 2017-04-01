#include<stdio.h>
#define n 2
float ave(float(*p)[3])
{
	int i;
	float v, sum = 0;
	for (i = 0; i < 3; i++)
	{
		sum += *(*p + i);
	}
	v = sum / 3;
	return v;
}
int main()
{
	int i,j,max;
	float a[n][3];
	float m[n],tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf_s("%f", &a[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		m[i] = ave(a + i);
	}
	
	for (i =0; i < n-1; i++)
	{
		max = i;
		for (j = i + 1; j < n; j++)
		{

			if (m[i] < m[j])
				max = j;
			if (max!= i)
			{
				tmp = m[max];
				m[max] = m[i];
				m[i] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%f\n", m[i]);
	return 0;

}
