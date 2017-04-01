#include<stdio.h>
int main()
{
	int i, j, k, sum = 0;
	for (i = 1; i <= 4; i++)
	for (j = 1; j <= 4; j++)
	for (k = 1; k <= 4; k++)
	{
		if (i != j&&i != k&&j != k)
		{
			printf("%d%d%d ", i, j, k);
			sum++;
		}
	}
	printf("\n");
	printf("sum=%d", sum);
	return 0;
}