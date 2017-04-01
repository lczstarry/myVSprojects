#include<iostream>
#include<string>
using namespace std;

template<class T>
class calculator
{
private:
	int maxSize;
	int top;
	T*st;
	int* p;
public:
	calculator()	//创建一个给定长度的顺序栈
	{
		maxSize = 100;
		top = -1;
		st = new T[maxSize];
	}
	~calculator()		//析构
	{
		delete[] st;
	}
	void Clear()		//清空栈的内容
	{
		top = -1;
	}
	bool Push(T item)		//入栈操作
	{
		if (top == maxSize - 1)
		{
			cout << "栈满溢出" << endl;
			return false;
		}
		else
		{
			top++;
			st[top] = item;
			return true;
		}
	}
	bool Pop(T&item)		//出栈操作
	{
		if (top == -1)
		{
			cout << "栈为空，不能进行删除操作" << endl;
			return false;
		}
		else
		{
			item = st[top--];
			return true;
		}
	}

	bool Pop()		//出栈不返回
	{
		if (top == -1)
		{
			cout << "栈为空，不能进行删除操作" << endl;
			return false;
		}
		else
		{
			top--;
			return true;
		}
	}

	T Top()		//读取栈顶元素的值
	{
		if (top == -1)
		{
			cout << "栈为空，不能读取栈顶元素" << endl;
			return 0;
		}
		else
		{
			return st[top];
		}
	}

	bool fu(char a)
	{
		if (a == '+' || a == '-' || a == '*' || a == '/')
			return true;
		else
			return false;
	}
	bool shu(char a)
	{
		if (a >= '0'&&a <= '9')
			return true;
		else
			return false;
	}
	bool kaikuohao(char a)
	{
		if (a == '(' || a =='[' || a == '{')
			return true;
		else
			return false;
	}
	bool bikuohao(char a)
	{
		if (a == ')' || a == ']' || a == '}')
			return true;
		else
			return false;
	}

	bool empty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	T fanzhuan()
	{
		int t = top;
		T temp;
		if (t == -1)
		{
			cout << "栈为空，不能读取栈顶元素" << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i <= t; i++)
			{
				for (int j = 0; j < t - i; j++)
				{
					temp = this->st[j];
					this->st[j] = this->st[j + 1];
					this->st[j + 1] = temp;
				}
			}
		}
		return 0;
	}
};
float exchange_num(char num_ch)  
{  
    switch(num_ch)  
    {  
    case'0':  
       return 0; break;  
    case'1':  
        return 1; break;  
    case'2':  
        return 2; break;  
	case'3':  
       return 3; break;  
    case'4':  
        return 4; break;  
    case'5':  
        return 5; break;  
    case'6':  
        return 6; break;  
    case'7':  
        return 7; break;  
    case'8':  
        return 8; break;  
    case'9':  
        return 9; break;  
    }  
}  

int isp(char a)
{
	if ('#' == a) return 0;
	if ('(' == a) return 1;
	if ('^' == a) return 7;
	if ('*' == a || '/' == a || '%' == a) return 5;
	if ('+' == a || '-' == a) return 3;
	if (')' == a) return 8;
	return 0;
}

int icp(char a)
{
	if ('#' == a) return 0;
	if ('(' == a) return 8;
	if ('^' == a) return 6;
	if ('*' == a || '/' == a || '%' == a) return 4;
	if ('+' == a || '-' == a) return 2;
	if (')' == a) return 1;
	return 0;
}

int main()
{
	string s;
	cout << "请输入10以内的算式" << endl;
	cin >> s;
	s += '#';
	calculator<char>InfixExp[100];
	calculator<float>InfixExpp[100];
	calculator<char>PostfixExp[100];

	int j = -1;
	int x = 0;
	for (int i = 0; s[i] != '#'; i++)
	{
		if (InfixExp->shu(s[i]))
		{
			PostfixExp->Push(s[i]);
		}
		if (InfixExp->kaikuohao(s[i]))
		{
			InfixExp->Push(s[i]);
			 j = i;
		}
		if (InfixExp->bikuohao(s[i]))
		{
			if (InfixExp->empty())
			{
				cout << "括号不匹配，请重新输入" << endl;
				InfixExp->Clear();
			}
			else
			{
				if (j == -1)
				{
					cout << "括号不匹配，请重新输入" << endl;
					InfixExp->Clear();
				}
				else
				{
					for (; InfixExp->Top() != s[j];)
					{
						char a;
						InfixExp->Pop(a);
						PostfixExp->Push(a);
					}
					InfixExp->Pop();
				}
			}
		}
		if (InfixExp->fu(s[i]))
		{

			while (!InfixExp->empty() && !InfixExp->kaikuohao(InfixExp->Top()) && icp(s[i]) <= isp(InfixExp->Top()))
			{
				char a;
				InfixExp->Pop(a);
				PostfixExp->Push(a);
			}
	
				InfixExp->Push(s[i]);
		

		}
	}

	while (!InfixExp->empty())
	{
		char a;
		InfixExp->Pop(a);
		PostfixExp->Push(a);
	}
	PostfixExp->Push('#');
	PostfixExp->fanzhuan();
	
	float result = 0;
	while (PostfixExp->Top() != '#')
	{

		if (PostfixExp->shu(PostfixExp->Top()))
		{
			
			char a;
			PostfixExp->Pop(a);

			InfixExpp->Push(exchange_num(a));
			
		}
		else
		{
			char  c;
			float a, b;

			PostfixExp->Pop(c);
			InfixExpp->Pop(a);
			InfixExpp->Pop(b);
			if ('+' == c)
			{
				result = a + b;
				InfixExpp->Push(result);
			}
			if ('-' == c)
			{
				result = b - a;
				InfixExpp->Push(result);
			}
			if ('*' == c)
			{
				result = a * b;
				InfixExpp->Push(result);
			}
			if ('/' == c)
			{
				result = b / a;
				InfixExpp->Push(result);
			}

		}
	}

		InfixExpp->Pop(result);
		cout << "算式结果为" << endl;
		cout << result << endl;
		return 0;
	}
	




	