using namespace std;
class Array
{
public:
	Array();                   //��������Ԫ�س�ʼ��Ϊ0
	int& getData(int i);	       //�����±�Ϊi������Ԫ�ص�����
	void print();                //��ӡ����������Ԫ�ص�ֵ
	void input();                //����������Ԫ�ؽ�������
private:
	int m_data[10];
};
Array::Array()
{
	m_data[10] = {0};
}
int& Array::getData(int i)
{
	return m_data[i];
}
void Array::print()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << m_data[i];
	}
}
void Array::input()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cin >> m_data[i];
	}
}