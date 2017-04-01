#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class stack{
private:
	int max;
	int top;
	char *str;  //存放栈元素的数组
public:
	stack(int size)
	{
		max = size;
		top = -1;
		str = new char[max];
	}
	stack()
	{
		top = -1;
	}
	~stack()
	{
		delete[]str;
	}
	void clear(){
		top = -1;
	}
	bool push(const char item)  //入栈操作
	{
		if (top == max - 1)
		{
			cout << "栈满溢出" << endl;
			return false;
		}
		else
		{
			str[++top] = item;
			return true;
		}
	}
	bool pop(char &item)
	{
		if (top == -1)
		{
			cout << "栈为空，不能进行删除操作" << endl;
			return false;
		}
		else
		{
			item = str[top--];
			return true;
		}
	}
	bool empty(){
		if (top == -1)
			return true;
		else
			return false;
	}
};
int main()
{
	char c;
	string st;
	int d = 1, j = 1;
	stack a(25);
	while (j){
		cout << "请输入表达式:";
		cin >> st;
		for (int i = 0; st[i] != '\0'&&d == 1; i++){
			switch (st[i]){
			case'(':
			case'[':
			case'{':
				a.push(st[i]);
				break;
			case')':
				a.pop(c);
				if (c == '(')
					break;
				else{
					d = 0;
					break;
				}
			case']':
				a.pop(c);
				if (c == '[')
					break;
				else{
					d = 0;
					break;
				}
			case'}':
				a.pop(c);
				if (c == '{')
					break;
				else{
					d = 0;
					break;
				}
			}
		}
		if (a.empty() && d == 1)
			cout << "配对正确!!" << endl;
		else
			cout << "配对错误!!" << endl;
		cout << "   *****************" << endl;
		cout << "   *  1、继续！！  *" << endl;
		cout << "   *  2、退出！！  *" << endl;
		cout << "   *****************" << endl;

		cin >> j;
		if (j == 2)
			j = 0;
		if (j == 1){
			system("cls");
			a.clear();
		}
	}
	system("cls");
	cout << "程序结束!!" << endl;
	return 0;
}
