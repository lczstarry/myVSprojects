#include<stdio.h>
int sum(int a[], int n)
{
	int x=0;
	if (n == 1)
		x = x + a[0];
	else
		x = a[n - 1] + sum(a, n - 1);
	return x;
}
int main()
{
	int x;
	int a[5] = { 1, 2, 3, 4, 5 };
	x=sum(a, 5);
	printf("%d", x);
	return 0;

}