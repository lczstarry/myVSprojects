#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	//sort(a, a + 10);
	int x;
	cin >> x;
	int left, mid, right;
	left = 0; right = 9;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			cout << mid << "是查找元素所在位置" << endl;
			return 0;
		}
		else if (a[mid] < x)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << "无此查找元素" << endl;
	return 0;
}