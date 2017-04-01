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
void BubbleSort(int data[], int n)
{
	int i, j;
	int flag = 0;
	for (i = 0; i<n; i++)
	{
		flag = 0;
		for (j = 1; j<n - i; j++)
		{
			if (data[j]<data[j - 1])
			{
				flag = 1;
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
		if (flag == 0)
			return;
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
	int data[6] = { 0, 8, 5, 6, 1, 9 };
	//input(data);
	BubbleSort(data, 6);
	output(data, 6);
	return 0;
}
