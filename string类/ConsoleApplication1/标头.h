#include<iostream>
using namespace std;
#include<cstring>

class String
{
public:
	String(const char *str=NULL);  //普通构造函数
	String(const String &other);     //拷贝构造函数
	~String();                   //析构函数
private://用主函数测试时将private改成public即可
	char *m_data; // 用于保存字符串
};
String::String(const char *str)
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
	}

}
String::String(const String &other)
{
		m_data = new char[strlen(other.m_data) + 1];
		strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);

}
String::~String()
{
	delete[]m_data;
}
