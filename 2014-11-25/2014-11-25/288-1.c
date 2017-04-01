#include<stdio.h>
#define N 10
void main()
{
	int a[N] = { 0 }, j, x, i;
	int *pi = a;
	for (i = 1; pi < a + 10; pi++)
	{
		*pi = i;
		i++;
	}
	pi = a;
	for (j = 0; pi < a + 5; pi++, j++)
	{
		x = *(pi + (N - 2 * j - 1));
		*(a + (N - 1 - j)) = *pi;
		*pi = x;
	}
	for (j = 0; j < 10; j++)
	{
		printf("%d  ", a[j]);
	}
}