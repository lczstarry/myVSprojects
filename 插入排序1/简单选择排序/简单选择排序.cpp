#include<iostream>
using namespace std;
void SelectionSort(int Data[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		for (int j = i; j < n; j++)
		{
			if (Data[j] < Data[k])
				k = j;
		}
		if (k != i - 1)
		{
			int t = Data[k];
			Data[k] = Data[i - 1];
			Data[i - 1] = t;
		}
	}
}
int main()
{
	int data[6] = { 0, 8, 5, 6, 1, 9 };
	//input(data);
	SelectionSort(data, 6);
	for (int i = 0; i < 6; i++)
	{
		cout << data[i] << ' ';
	}
}