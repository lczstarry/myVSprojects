
#include <iostream>
using namespace std;
class Set
{
private:
	int num[100];
	int len;

public:
	Set(){ len = 0; };//默认构造函数 
	Set(int data[], int n);//用数组构造集合 
	void InitSet();//初始化函数
	void Clc();//保证元素互异性函数 
	void Print();//打印数组元素 

	friend bool Append(Set &A, int n); //添加一个元素n 
	friend void Dele(Set &A, int n); //删除一个元素n 
	friend Set operator + (Set &A, Set &B);//计算A U B 的结果 
	friend Set operator *(Set &A, Set &B);//计算集合A,B的交集 
	friend bool Judge(Set &A, int n);//判断元素n是否在集合中 
	Set& operator  = (Set &A);// 重载赋值运算符
	friend Set operator  -=(Set &A, Set &B);// 复合赋值运算符

};
/*
data[]：数组
n：数组长度
*/
Set::Set(int data[], int n)
{
	len = n;
	for (int i = 0; i<len; i++)
		num[i] = data[i];

	Clc();
}
/*初始化函数*/
void Set::InitSet()
{
	cout << "输入Set长度len：";
	cin >> len;

	cout << "输入Set元素：";
	for (int i = 0; i<len; i++)
		cin >> num[i];

	Clc();
}
/*保证元素互异性函数，清除相同元素 */
void Set::Clc()
{
	for (int i = 0; i<len; i++)
	{
		for (int j = i + 1; j<len; j++)
		if (num[i] == num[j])
		{
			for (int k = j; k<len - 1; k++)
				num[k] = num[k + 1];

			len--;
			j--;
		}
	}
}
//打印数组元素 
void Set::Print()
{
	cout << "集合元素个数为：" << len << endl;
	for (int i = 0; i<len; i++)
		cout << num[i] << " ";
	cout << endl;
}
/*
友元函数，在集合A中添加一个元素n，添加成功返回true
*/
bool Append(Set &A, int n)
{
	if (A.len == 100)
		return false;
	else
		A.num[A.len++] = n;

	A.Clc();
	return true;
}
/*
友元函数，在集合A中删除一个元素n，
*/
void Dele(Set &A, int n)
{
	for (int i = 0; i<A.len; i++)
	{
		if (A.num[i] == n)
		{
			for (int j = i; j<A.len - 1; j++)
				A.num[j] = A.num[j + 1];
			A.len--;
			break;
		}
	}
}
/*计算集合并集*/
Set operator + (Set &A, Set &B)
{
	Set C;
	C.len = A.len;
	for (int i = 0; i < A.len; i++)
	{
		C.num[i] = A.num[i];
	}
	for (int i = 0; i < B.len; i++)
	{
		int j = 0;
		for (j = 0; j < A.len; j++)
		{
			if (A.num[j] == B.num[i])
				break;
		}
		if (j == A.len)
		{
			C.num[C.len++] = B.num[i];
		}
	}
	return C;
}
/*计算集合交集*/
Set operator *(Set &A, Set &B)
{
	Set C;

	for (int i = 0; i<A.len; i++)
	{
		for (int j = 0; j<B.len; j++)
		{
			if (A.num[i] == B.num[j])
			{
				C.num[C.len++] = A.num[i];
				break;
			}
		}
	}

	return C;
}
//判断元素n是否在集合中 
bool Judge(Set &A, int n)
{
	for (int i = 0; i<A.len; i++)
	{
		if (A.num[i] == n)
			return true;
	}
	return false;
}
Set& Set::operator  = (Set &A)
{
	len = A.len;

	for (int i = 0; i <A.len; i++)
	{
		num[i] = A.num[i];
	}
	return *this;
}
Set operator  -=(Set &A, Set &B)
{
	for (int i = 0; i < B.len; i++)
	{
		for (int j = 0; j < A.len; j++)
		{
			if (A.num[j] == B.num[i])
			{
				for (int k = j; k < A.len - 1; k++)
					A.num[k] = A.num[k + 1];
				A.len--;
				j--;

			}
		}
	}
	return A;
}