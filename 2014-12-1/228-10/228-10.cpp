#include <stdio.h>
#include <string.h>
void replace(char *s1, char *s2, char *str1, char *str2)
{
	char *t0, *t1, *t2;
	while (*s1 != '\0')
	{
		t1 = str1;
		if (*s1 == *t1)
		{
			for (t0 = s1, t1 = str1; (*t0 == *t1&&*t1 != '\0'); t0++, t1++)
			{
				*s2++ = *s1++;
			
				if (*(t1 + 1) == '\0')
				{
					s2 -= strlen(str1);
					for (t2 = str2; *t2 != '\0';)
						*s2++ = *t2++;
				}
			}
		}
		else
			*s2++ = *s1++;
	}
	*s2 = '\0';
}

int main()
{
	static char s1[] = "abcef ababcd abab";
	static char s2[25];
	replace(s1, s2, "abc", "XYZ");
	printf("%s\n", s2);
}