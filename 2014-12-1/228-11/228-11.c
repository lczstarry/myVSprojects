#include <stdio.h>
#include <string.h>
int main()
{
	char str[10][30] = { 0 };
	char tem[30] = { 0 };
	int i, j;
	printf("请输入10个单词:");
	for (i = 0; i<10; i++)//输入
		scanf_s("%s", str[i]);
	for (i = 0; i<9; i++)//排序
	for (j = i + 1; j<10; j++)
	if (strcmp(str[i], str[j])>0)
	{
		strcpy_s(tem, 10,str[i]);
		strcpy_s(str[i],10, str[j]);
		strcpy_s(str[j],10, tem);
	}
	printf("这10个单词按照字典排序输出为:\n");
	for (i = 0; i<10; i++)// 输出
	{
		printf("%s\n", str[i]);
	}
	return 0;
}