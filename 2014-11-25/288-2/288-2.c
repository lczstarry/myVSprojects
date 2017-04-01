#include<stdio.h>
int*min(int array[], int n)
{
	int i1;
	int *pi1 = &array[0];
	for (i1 = 1; i1<n; i1++)
	if (array[i1]<*pi1)
		pi1 = &array[i1];
	return pi1;
}
int main()
{
	int array[10] = { 5, 15, 25, 36, 47, 58, 69, 78, 56, 90 };
	int *pi;
	pi = min(array, 10);
	printf("%d", *pi);
	return 0;
}
