#include<iostream>
using namespace std;

template<class T>
class node
{
public:
	T data;
	node*next;
	node(int a, node*b = NULL)
	{
		data = a;
		next = b;
	}
};

template<class T>
class queue
{
private:
	int size[10];
	node<T>*front[10];
	node<T>*rear[10];
public:
	queue()
	{
		for (int i = 0; i < 10; i++)
		{
			size[i] = 0;
			front[i] = rear[i] = NULL;
		}
	}
	bool enqueue(const T item)//item入队，插入队尾
	{
		int i = item;
		if (rear[i] == NULL)
		{
			front[i] = rear[i] = new node<T>(item, NULL);
		}
		else
		{
			rear[i]->next = new node<T>(item, NULL);
			rear[i] = rear[i]->next;
		}
		size[i]++;
		return true;
	}
	void paixu()
	{
		int judge = 1;
		node<T>*head = NULL;
		node<T>*tail = NULL;
		node<T>*t = NULL;
		for (int i = 0; i < 10; i++)
		{
			if (front[i] != NULL&&judge)
			{
				head = t = front[i];
				judge = 0;
			}
			if (front[i] != NULL&&!judge)
			{
				t->next = front[i];
				t = t->next;
			}
		}
		cout << "输出所有元素" << endl;
		while (head != NULL)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
};
int main()
{
	queue<int> a;
	cout << "请输入0-9整数" << endl;
	int n;
	cin >> n;
	while (n>=0)
	{
		a.enqueue(n);
		cin >> n;
	}
	a.paixu();
	return 0;
}