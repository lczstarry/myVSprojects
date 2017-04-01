#include <stdio.h>
int love(int m)
{
	if (m == 0 || m == 1)
		printf("%d", m % 2);
	else
	{
		love(m / 2);
		printf("%d", m % 2);
	}
}
void main()
{
	int n;
	scanf_s("%d", &n);
	printf("其二进制数为  ");
	love(n);
}