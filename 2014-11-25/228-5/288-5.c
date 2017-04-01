#include <stdio.h>
int main()
{
	int i, j; 
	float summ[10];
	float score[10][3]; 
	float sum(float(*p)[3]);
	for (i = 0; i<10; i++)     
	for (j = 0; j<3; j++)     
		scanf_s("%f", &score[i][j]);
	
	for (i = 0; i<10; i++)     
	{
		for (j = 0; j<3; j++)     
			printf("%f\t", score[i][j]);
		printf("\n");
	}
	for (i = 0; i < 10; i++)
	{
		summ[i] = sum(score + i);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%f\n",summ[i]);
	}
	return 0;

}
float sum(float(*p)[3])
{
	int i;
	float sum = 0;
	for (i = 0; i<3; i++)
		
		sum += *(*p + i);
	return sum ;
}


