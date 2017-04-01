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
			
			if (curLen < 0) 					//表空, 中止操作返回
			{
				cout << "List is Empty!";
				return false;
			}
			int m = 0;					//假定0号元素的值最小
			for (int i = 1; i < curLen; i++)
			{	//循环, 寻找具有最小值的元素
				if (arrayList[i] < arrayList[m])
				{
					m = i; 	//让m指向当前具最小值的元素

				}
			} 	
			min = arrayList[m];
			arrayList[m] = arrayList[curLen-1];
			curLen--;//空出位置由最后元素填补, 表最后元素位置减1
			cout << min  << endl;
			return min;
		}
	}
	void two(const int x)
	{
		int i = 0, j;
		while (i <= curLen) 		//循环, 寻找具有值x的元素并删除它
		if (arrayList[i] == x)
		{ 		//删除具有值x的元素, 后续元素前移
			for (j = i; j < curLen; j++)
				arrayList[j] = arrayList[j + 1];
			curLen--;		//表最后元素位置减1
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
		while (i <= curLen) //循环, 寻找具有值x的元素并删除它
		if (arrayList[i] >= s && arrayList[i] <= t)
		{ 	//删除满足条件的元素, 后续元素前移
			for (j = i; j < curLen; j++)
				arrayList[j] = arrayList[j + 1];
			curLen--;   			//表最后元素位置减1
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
