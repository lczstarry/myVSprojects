#include<stdio.h>
#include<string.h>

char* DelStr(char* str1, char* str2)
{
	int i, j;
	int iLen1, iLen2;
	int iFlag, iPos;
	char s1[128 + 1], s2[128 + 1];

	memset(s1, 0x00, sizeof(s1));
	memset(s2, 0x00, sizeof(s2));

	strcpy_s(s1,129 ,str1);
	strcpy_s(s2,129, str2);

	iLen1 = strlen(s1);
	iLen2 = strlen(s2);

	for (i = 0; i <= iLen1 - iLen2; i++)
	{
		iFlag = 0;
		iPos = i;
		for (j = 0; j< iLen2; j++, iPos++)
		{
			if (s1[iPos] != s2[j])
			{
				iFlag = 1;
				break;
			}
		}

		if (iFlag == 0)
		{
			memmove(s1 + i, str1 + i + iLen2, iLen1 - iLen2);
			s1[iLen1 - iLen2] = 0;
			iLen1 = strlen(s1);
		}
	}
	puts(s1);
}
int main()
{

	char str1[80];
	char str2[80];

	gets_s(str1, 80);
	gets_s(str2, 80);
	DelStr(str1, str2);

	
	return 0;
}