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
void merge(int data[], int start, int mid, int end)
{
	int len1 = mid - start + 1, len2 = end - mid;
	int i, j, k;
	int *left = new int[len1];
	int *right = new int[len2];
	for (i = 0; i<len1; i++)
		left[i] = data[i + start];
	for (i = 0; i<len2; i++)
		right[i] = data[i + mid + 1];
	i = 0; j = 0;
	for (k = start; k<end; k++)
	{
		if (i == len1 || j == len2)
			break;
		if (left[i] <= right[j])
			data[k] = left[i++];
		else
			data[k] = right[j++];
	}
	while (i<len1)
		data[k++] = left[i++];
	while (j>len2)
		data[k++] = left[j++];
	delete[]left;
	delete[]right;
}
void MergeSort(int data[], int start, int end)
{
	if (start<end)
	{
		int mid = (start + end) / 2;
		MergeSort(data, start, mid);
		MergeSort(data, mid + 1, end);
		merge(data, start, mid, end);
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
	MergeSort(data, 0, 5);
	output(data, 6);
	return 0;
}
