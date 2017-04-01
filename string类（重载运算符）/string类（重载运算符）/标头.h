#include<iostream>
#include<cstring>
using namespace std;
class String
{
public:
	String(const char *str = NULL);
	
	
public:
	friend String operator+(String&s1, String&s2);
	bool operator <(const String&s);
	friend ostream& operator<<(ostream&out, String&s);
	friend istream& operator>>(istream&in, String&s);
	char* operator ()(int m, int n);

private:
	char*m_data;
	int len;
};


String::String(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[5];
		m_data ="NULL";
		len=0;
	}
	else
	{
		m_data = new char[strlen(str) + 1];
		strcpy_s(m_data, strlen(str) + 1, str);
		len = strlen(str);
	}
	
}

String operator+(String&s1, String&s2)
{
	String s3;
	s3.m_data = new char[ s1.len+s2.len+ 1];
	int i = 0;
	for (; i < s1.len; i++)
	{
		s3.m_data[i] = s1.m_data[i];
		
	}
	for (; i < s1.len + s2.len; i++)
	{
		s3.m_data[i] = s2.m_data[i-s1.len];
	}
	s3.m_data[i] = '/0';
	s3.len = s1.len + s2.len;
	return s3;
}
bool String::operator <(const String&s)
{
	if (len < s.len)
		return true;
	else
		return false;
}
ostream& operator<<(ostream&out, String&s)
{
	out << s.m_data;
	return out;
}
istream& operator>>(istream&in, String&s)
{
	in >> s.m_data;
	s.len = strlen(s.m_data);
	return in;
}
char* String::operator ()(int m, int n)
{
	char*p = new char[n-m+1];
	
	int j = 0;
	for (int i=m-1; i <n; i++,j++)
	{
		p[j] = m_data[i];
	}
	p[j] = '\0';
	return p;
}