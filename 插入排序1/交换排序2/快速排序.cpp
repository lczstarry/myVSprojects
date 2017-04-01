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
int Partition(int data[], int left, int right)
{
	int pivot = data[left];
	while (left<right)
	{
		while (left<right && data[right]>pivot)
			right--;
		data[left] = data[right];
		while (left<right && data[left] <= pivot)
			left++;
		data[right] = data[left];
	}
	data[left] = pivot;
	return left;
}
void QuickSort(int data[], int left, int right)
{
	if (left<right)
	{
		int p = Partition(data, left, right);
		QuickSort(data, left, p - 1);
		QuickSort(data, p + 1, right);
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
	QuickSort(data, 0, 5);
	output(data, 6);
	return 0;
}
