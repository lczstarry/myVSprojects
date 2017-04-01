#include<iostream>
using namespace std;

class node
{
public:
	int element;
	int number;
	node *next;
};

class suoyin
{
public:
	node*head = new node;
	node*tail = new node;
	suoyin(int Array[], int n)
	{
		int i = 0;
		for (; i < n; i++)
		{
			node*p = new node;
			p->element = Array[i];
			p->number = i;
			if (i == 0)
			{
				head = tail = p;
			}
			else
			{
				tail->next = p;
			}
			p->next = NULL;
			tail = p;
		}
	}
	void show()
	{
		node*q = new node;
		q = head;
		while (q != NULL)
		{

				cout << q->number << "  " << q->element << endl;
				q = q->next;
			

		}
		cout << endl;
	}
};


void main()
{
	int a[5];
	int b = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		b++;
	}
	suoyin s(a, b);
	s.show();
}
