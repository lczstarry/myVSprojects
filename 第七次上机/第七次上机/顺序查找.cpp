#include<iostream>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	for (int i = 0; i < 10; i++)
	{
		if (x == a[i])
			cout << i << "�ǲ���Ԫ������λ��" << endl;
	}
	return 0;
}