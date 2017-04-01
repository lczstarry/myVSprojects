#include<stdio.h>
#include<math.h>
float distance(float x1, float y1, float x2, float y2)
{
	

	float x,y;
	x = (x1 - x2)*(x1 - x2) + (y1 - y2) *(y1 - y2);
	y = sqrt(x);
	return y;
}
void main()
{
	float x1, x2, y1, y2;
	float y;
	scanf_s("%f%f%f%f", &x1, &y1, &x2, &y2);
	y = distance(x1, y1, x2, y2);
	printf("%f", y);
}

