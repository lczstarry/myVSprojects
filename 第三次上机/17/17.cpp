#include<iostream>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int strcmp(char *s1, char *s2)
{
	int count = 0;
	while (s1[count] != '\0'&&s2[count] != '\0')
	{
		if (s1[count] < s2[count])
			return -1;
		else if (s1[count] > s2[count])
			return 1;
		else 
			return 0;
		count++;
	}
	if (s1[count] == '\0'&&s2[count] != '\0')
	{
		return -1;
	}
	else if (s1[count] != '\0'&&s2[count] == '\0')
	{
		return -1;
	}

		return 0;
}

int main()
{
	char a[20];
	char b[20];
	int  m, n;
	cin >> m;
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		cin >> b[j];
	}
	if (strcmp(a, b) == -1)
	{
		cout << "a字符串小于b" << endl;
	}
	else if (strcmp(a, b) == 0)
	{
		cout << "a,b字符串相等" << endl;
	}
	else if (strcmp(a, b) == 1)
	{
		cout << "a字符串大于b" << endl;
	}
	return 0;
}