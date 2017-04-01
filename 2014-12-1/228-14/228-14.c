#include<stdio.h> 
#include<string.h> 
void main()
{
	char string1[200]; //用于存放输入的字符串 
	char string2[200]; //用于存放倒序后的字符串 
	int invertion(char *ch1, char *ch2); //声明函数 
	printf("Please input a sentences:\n");
	gets_s(string1,200); //这里不要用scanf,因为scanf遇到空白符就会结束 
	printf("Your inputed sentences is:%s\n", string1);

	invertion(string1, string2);
	printf("The invertion sentences is:%s\n", string2);
	getchar();
}

int invertion(char *ch1, char *ch2)/*char1 接收实参传过来的原字符串指针 char2 接收倒序后的新字符串返回主函数*/
{
	int count = 1, num = 0;
	char *ch = ch1;
	for (; *ch1 != '\0'; ch1++)// 统计单词个数 
	{
		if (*ch1 == ' ')
			count++; //单词数等于空格数加1，前面把count初始化为1就是这个原因 
		if (*ch1 == ' '&&*(ch1 + 1) == ' ') //防止单词之间有2个空格符而多计数了一个单词数 
			count--;
	}
	printf("count = %d\n", count);
	ch1 = ch1 - 1;//前面的ch1经过循环之后已经指向字符串的结束标志'\0'，这里减1是为了让它指向字符串的最后一个字符 
	while (ch1 >= ch)//让ch1从指向string1的最后一个字符开始往前递减，当减到字符串的首个字符时结束 
	{
		int j = num; //保存num,后面要用到这个数 
		if (*ch1 != ' ')//记录每个单词的长度 ，以空格符作为标志 
			num++;
		else   // 知道了每个单词的长度之后，就可以用循环将字符以单词为单位写入数组string中，这样的话单词内就不会倒序了 
		{
			for (int i = 1; i <= j; i++, num--)
				*(ch2 - num) = *(ch1 + i);
			*ch2 = *ch1;
		}
		ch1--;
		ch2++;
	}
	for (int i = 1; i <= num; i++, ch2++)//因为string1的第一个单词前没有空格符，肯定输不出来，所以单独用一个循环将其输出 
		*(ch2 - num) = *(ch1 + i);
	*ch2 = '\0'; //string2的结束标志 
}