#include <iostream>
#include <cstring>
using namespace std;
class String
{
public:
	String( char *str = NULL);  //普通构造函数
	String(const String &other);     //拷贝构造函数
	~String();                   //析构函数
	void display();            //输出函数
public:
	char *m_data; // 用于保存字符串
	int len;
};
class Edit_string :public String
{
public:
	Edit_string(char*str=NULL) :String(str){ p = m_data; }//构造函数
	void E_insert(char*str,int n);        //插入
	void E_delete(int n,int m);          //删除
	void E_replace(char*str,int n, int m);//替换
public:
	char*p;

};
String::String( char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		m_data[0] = ' ';
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy_s(m_data, strlen(str) + 1, str);
		len = strlen(str);
	}

}
String::String(const String &other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
	len = strlen(other.m_data);

}
String::~String()
{
	delete[]m_data;
}
void String::display()
{
	
	cout << m_data;
}
void Edit_string::E_delete(int n, int m)
{
	for (int i = 0; i < m - n + 1; i++)
	{
		p[n] = p[m + 1];
		n++;
		m++;
	}
	int k = len - m + n - 1;
	
	for (int i = 0; i < m - n + 1; i++)
	{
		p[k] = NULL;
		k++;
	}
	
}
void Edit_string::E_replace(char*str, int n, int m)
{
	if (str == NULL)
	{
		cout << "请重新输入" << endl;
	}
	else
	{
		int k = n;
		for (int i = 0; i < m - n + 1; i++)
		{
			p[k] = str[i];
			k++;
		}
	}
}
void Edit_string::E_insert(char*str, int n)
{
	int length;
	length = strlen(str);
	char*q = new char[len + 1];
	strcpy_s(q,len+1,p);
	delete[]m_data;
	m_data = new char[len + length + 1];
	
	int i = 0;
	for (; i < n; i++)
	{
		m_data[i] = q[i];
	}
	int k = i;
	int j = i;
	
	
	for ( i = 0; i < length; i++)
	{
		m_data[j] = str[i];
		j++;
	}

	for (; k < len; k++)
	{
		m_data[j] = q[k];
		j++;
	}
	m_data[j] = '\0';
	len = len + length;
	delete[]q;
}