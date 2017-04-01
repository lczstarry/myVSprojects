using namespace std;
class Array
{
public:
	Array();                   //所有数组元素初始化为0
	int& getData(int i);	       //返回下标为i的数组元素的引用
	void print();                //打印出所有数组元素的值
	void input();                //对所有数组元素进行输入
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