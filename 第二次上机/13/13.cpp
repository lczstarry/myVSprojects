#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class stack{
private:
	int max;
	int top;
	char *str;  //���ջԪ�ص�����
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
	bool push(const char item)  //��ջ����
	{
		if (top == max - 1)
		{
			cout << "ջ�����" << endl;
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
			cout << "ջΪ�գ����ܽ���ɾ������" << endl;
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
		cout << "��������ʽ:";
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
			cout << "�����ȷ!!" << endl;
		else
			cout << "��Դ���!!" << endl;
		cout << "   *****************" << endl;
		cout << "   *  1����������  *" << endl;
		cout << "   *  2���˳�����  *" << endl;
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
	cout << "�������!!" << endl;
	return 0;
}
