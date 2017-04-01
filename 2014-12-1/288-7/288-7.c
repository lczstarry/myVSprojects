#include<stdio.h>
char*lianjie(char*a, char*b)
{
	int i = 0, j = 0;
	while (a[i] != '\0')
		i++;
	while (b[j] != '\0')
	{

		a[i++] = b[j++];
	}
	a[i] = '\0';
	return a;

}
int main()
{
	char p1[40];
	char p2[40];
	gets_s(p1,40);
	gets_s(p2,40);
	lianjie(p1, p2);
	puts(p1);
	return 0;


}