#include <stdio.h>
#include <string.h>
int main()
{
	char str[10][30] = { 0 };
	char tem[30] = { 0 };
	int i, j;
	printf("������10������:");
	for (i = 0; i<10; i++)//����
		scanf_s("%s", str[i]);
	for (i = 0; i<9; i++)//����
	for (j = i + 1; j<10; j++)
	if (strcmp(str[i], str[j])>0)
	{
		strcpy_s(tem, 10,str[i]);
		strcpy_s(str[i],10, str[j]);
		strcpy_s(str[j],10, tem);
	}
	printf("��10�����ʰ����ֵ��������Ϊ:\n");
	for (i = 0; i<10; i++)// ���
	{
		printf("%s\n", str[i]);
	}
	return 0;
}