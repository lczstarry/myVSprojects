#include<stdio.h>
int main()

{
	long int a;
	int b, c, d, e, f;
	scanf_s("%ld", &a);
	while (a >= 1 && a <= 99999)
	{
		if (a / 10000 >= 1 && a / 10000<10)
		{
			b = (int)(a / 10000);
			c = (int)((a - b * 10000) / 1000);
			d = (int)((a - b * 10000 - c * 1000) / 100);
			e = (int)((a - b * 10000 - c * 1000 - d * 100) / 10);
			f = a - b * 10000 - c * 1000 - d * 100 - e * 10;
			printf("%d+%d+%d+%d+%d=", b, c, d, e, f); 
			printf("%d", b + c + d + e + f);
			break;
		}
		if (a / 1000 >= 1 && a / 1000<10)
		{
			b = (int)(a / 1000);
			c = (int)((a - b * 1000) / 100);
			d = (int)((a - b * 1000 - c * 100) / 10);
			e = a - b * 1000 - c * 100 - d * 10;
			printf("%d+%d+%d+%d=", b, c, d, e); 
			printf("%d", b + c + d + e );
			break;
		}
		if (a / 100 >= 1 && a / 100<10)
		{
			b = (int)(a / 100);
			c = (int)((a - b * 100) / 10);
			d = a - b * 100 - c * 10;
			printf("%d+%d+%d=", b, c, d);
			printf("%d", b + c + d);
			break;
		}
		if (a / 10 >= 1 && a / 10<10)
		{
			b = (int)(a / 10);
			c = a - b * 10;
			printf("%d+%d=", b, c);
			printf("%d", b + c);
			break;
		}
		if (a >= 1 && a<10);
		{
			printf("%d=%d", a,a);
			
			break; 
		}
	}
	return 0;
}