#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int find_last(string a, string b)
{
	int judge = 0;
	for (int i = 0; i < a.length(); i++)
	{
		int t;
		int k = i;
		for (int j = 0; j < b.length(); j++)
		{
			t = k;
			if (a[k] == b[j])
				k++;
			else if (a[t] != b[j])
			{
				break;
			}
			if (j == b.length() - 1)
			{
				judge = i + 1;
			}
		}
	}
	return judge;
}

int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	cout << find_last(a, b);
	return 0;
}