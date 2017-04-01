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
void ShellSort(int data[], int n)
{
	int d = n / 2;
	while (d >= 1)
	{
		for (int k = 0; k<d; k++)
		{
			for (int i = k + d; i<n; i += d)
			{
				int temp = data[i];
				int j = i - d;
				while (j >= k && data[j]>temp)
				{
					data[j + d] = data[j];
					j -= d;
				}
				data[j + d] = temp;
			}
		}
		d = d / 2;
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
	ShellSort(data, 6);
	output(data, 6);
	return 0;
}
