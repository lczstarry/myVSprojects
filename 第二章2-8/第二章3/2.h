#include <iostream>
using namespace std;

class ArrayList
{


public:
	int*arrayList;
	int maxSize;
	int curLen;
	int position;
	ArrayList(const int size)
	{
		maxSize = size;
		arrayList = new int[maxSize];
		curLen = size;
		position = 0;
	}
	~ArrayList()
	{
		delete[] arrayList;
	}
	void clear()
	{
		delete[] arrayList;
		curLen = 0;
		position = 0;
		arrayList = new int[maxSize];
	}
	int one()
	{
		{
			int min;
			
			if (curLen < 0) 					//���, ��ֹ��������
			{
				cout << "List is Empty!";
				return false;
			}
			int m = 0;					//�ٶ�0��Ԫ�ص�ֵ��С
			for (int i = 1; i < curLen; i++)
			{	//ѭ��, Ѱ�Ҿ�����Сֵ��Ԫ��
				if (arrayList[i] < arrayList[m])
				{
					m = i; 	//��mָ��ǰ����Сֵ��Ԫ��

				}
			} 	
			min = arrayList[m];
			arrayList[m] = arrayList[curLen-1];
			curLen--;//�ճ�λ�������Ԫ���, �����Ԫ��λ�ü�1
			cout << min  << endl;
			return min;
		}
	}
	void two(const int x)
	{
		int i = 0, j;
		while (i <= curLen) 		//ѭ��, Ѱ�Ҿ���ֵx��Ԫ�ز�ɾ����
		if (arrayList[i] == x)
		{ 		//ɾ������ֵx��Ԫ��, ����Ԫ��ǰ��
			for (j = i; j < curLen; j++)
				arrayList[j] = arrayList[j + 1];
			curLen--;		//�����Ԫ��λ�ü�1
		}
		else i++;
		
	}
void three(const int s, const int t)
	{
		if (curLen <= 0 || s >= t)
		{
			cout << "List is empty or parameters are illegal!";
			
		}
		int i = 0, j;
		while (i <= curLen) //ѭ��, Ѱ�Ҿ���ֵx��Ԫ�ز�ɾ����
		if (arrayList[i] >= s && arrayList[i] <= t)
		{ 	//ɾ������������Ԫ��, ����Ԫ��ǰ��
			for (j = i; j < curLen; j++)
				arrayList[j] = arrayList[j + 1];
			curLen--;   			//�����Ԫ��λ�ü�1
		}
		else i++;
	}
	
};

void display(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}
