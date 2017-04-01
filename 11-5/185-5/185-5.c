#include<stdio.h>
int isPerfectnum(int number)
{
	int i, sum = 1;
	for (i = 2; i < number; i++)
	{
		if (number%i == 0)
		{
			sum += i;
		}
	}
	if (sum == number)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int i, j;
	for (i = 1; i <= 1000; i++)
	{
		j = isPerfectnum(i);
		if (j == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}