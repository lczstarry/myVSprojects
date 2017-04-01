#include"±êÍ·.h"
void main()
{
	const char*p = "dsgag    ";

	String s1(p);
	cout << s1.m_data;
	
	String s3("sadhfojsah   ");
	cout << s3.m_data;
	

	String s2 ( s1);//»òString s2= s1;
	cout << s2.m_data;

	
}