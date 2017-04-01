#include<stdio.h>
int main()
{
	int  b[20][2], i, j, k;
	int a[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

	j = 0;
	for (i = 0; i < 20; i++)
	{
		k = a[i] % 2;
		if (k == 0)
		
		{
			b[j][0] = a[i];
			printf("\n%d", b[j][0]);
			j++;
			
		}
		if (k != 0)
		
		{
			b[j][1] = a[i];
			printf("\t%d", b[j][1]);
			j++;

		}


	}
	
	return 0;
}