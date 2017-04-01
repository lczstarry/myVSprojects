#include <stdio.h>
int main()
{
	int a, b, n;
	scanf_s("%d%d", &a, &b);
	for (n = (a + b) / 2; n > 0; n--)
	{
		if ((a%n == 0) && (b%n == 0))
			break;
	}
	printf("%d", n);
	return 0;
}