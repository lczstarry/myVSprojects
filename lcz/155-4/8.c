#include<stdio.h>
int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i, j, k;
	for (i = 1, j = 1; i <= 1000; j = j + i)
	{
		if (j > 10)
			j = j % 10;
		if (j == 0)
			j = 10;
		for (k = 0; k<10; k++)    
		if (j == a[k])
			a[k] = 0;
		i++;
	}
	printf("ÍÃ×ÓÔÚµÄ¶´:\n");
	for (k = 0; k<10; k++)      
	if (a[k] != 0)
		printf("%3d", a[k]);
	return 0;
}