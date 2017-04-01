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
			cout << i << "是查找元素所在位置" << endl;
	}
	return 0;
}