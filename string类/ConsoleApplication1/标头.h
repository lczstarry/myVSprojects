#include<iostream>
using namespace std;
#include<cstring>

class String
{
public:
	String(const char *str=NULL);  //��ͨ���캯��
	String(const String &other);     //�������캯��
	~String();                   //��������
private://������������ʱ��private�ĳ�public����
	char *m_data; // ���ڱ����ַ���
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
