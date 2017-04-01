#include<iostream>
using namespace std;
void input(int data[])
{
	int i;
	cout << "任意输入6个数：";
	for (i = 0; i<6; i++)
		cin >> data[i];
	cout << endl;
	cout << "原始数据为：";
	for (i = 0; i<6; i++)
		cout << data[i] << "  ";
	cout << endl;
}
void InsertSort(int data[], int n)
{
	int p, i;
	for (p = 1; p<n; p++)
	{
		int temp = data[p];
		i = p - 1;
		while (i >= 0 && data[i]>temp)
		{
			data[i + 1] = data[i];
			i--;
		}
		data[i + 1] = temp;
	}
}
void output(int data[], int n)
{
	int i = 0;
	cout << endl << "不降序排序后：";
	for (; i<n; i++)
		cout << data[i] << "  ";
	cout << endl << endl;
}
int main()
{
	int data[6] = { 0,8,5,6,1,9 };
	//input(data);
	InsertSort(data, 6);
	output(data, 6);
	return 0;
}
