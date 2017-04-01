#include<stdio.h>
char * copy(char*p1, char*p2)
{
	while (*p2 != '\0')
	{
		*p1++ = *p2++;
	}
	*p1 = '\0';
	return p1;
}
int main()
{
	char carr[15];
	char a[15];
	gets_s(carr);
	copy(a, carr);
	puts(carr);
	puts(a);
	return 0;

}
