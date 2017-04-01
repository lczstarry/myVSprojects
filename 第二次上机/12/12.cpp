#include <stdio.h>
#define MAX_SIZE 100
int main()
{
	int stack[MAX_SIZE];
	int top;
	int num;
	int temp;
	printf("请输入十进制数：");
	scanf_s("%d", &num);
	printf("请输入待转换的进制：");
	scanf_s("%d", &temp);
	top = 0;
	do
	{
		stack[top++] = num % temp;
		num /= temp;
	} while (num);
	while (top)
	{
		printf("%d", stack[--top]);
	}
	printf("\n");
	return 0;
}