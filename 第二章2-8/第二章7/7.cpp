#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;
	node*prev;
};

node*head = (node*)malloc(sizeof(node));
node*tail = (node*)malloc(sizeof(node));

node *create_list(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		node*pnew = (node*)malloc(sizeof(node));
		cin >> pnew->data;
		if (0 == i)
		{
			head = tail = pnew;
		}
		else
		{
			tail->next = pnew;
			pnew->prev = tail;
		}
		pnew->next = NULL;
		tail = pnew;
	}
	return 0;
}

void show(node*head)
{
	node*p = (node*)malloc(sizeof(node));
	p = head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

void change(int n)
{
	int i;
	node*p = (node*)malloc(sizeof(node));
	p = NULL;
	node*p1 = (node*)malloc(sizeof(node));
	node*t = (node*)malloc(sizeof(node));
	t = NULL;
	node*temp = (node*)malloc(sizeof(node));
	temp = NULL;
	p1 = NULL;
	for (i = 0; i<n; i++)     // 头为p 全为0的 链表
	{
		node*pnew = (node*)malloc(sizeof(node));
		pnew->data = 0;
		if (0 == i)
		{
			p = t = pnew;
		}
		else
		{
			t->next = pnew;
			pnew->prev = t;
		}
		pnew->next = NULL;
		t = pnew;
	}
	p1 = p;
	temp = head;
	while (p1&&temp)                      //将原链表复制到0链表中
	{
		p1->data = temp->data;
		p1 = p1->next;
		temp = temp->next;
	}
	p1 = p;
	temp = head;
	if (n % 2 == 1)
	{
		for (i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				temp->data = p1->data;
				temp = temp->next;
				p1 = p1->next;
			}
			else
			{
				if (p1->next != NULL)
				{
					p1 = p1->next;
				}
			}
		}
		p1 = t;
		for (i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				temp->data = p1->data;
				temp = temp->next;
				p1 = p1->prev;
			}
			else
			{
				if (p1->prev != NULL)
				{
					p1 = p1->prev;
				}
			}
		}
	}
	if (n % 2 == 0)
	{
		for (i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				temp->data = p1->data;
				temp = temp->next;
				p1 = p1->next;
			}
			else
			{
				if (p1->next != NULL)
				{
					p1 = p1->next;
				}
			}
		}
		p1 = t;
		for (i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				temp->data = p1->data;
				temp = temp->next;
				p1 = p1->prev;
			}
			else
			{
				if (p1->prev != NULL)
				{
					p1 = p1->prev;
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	create_list(n);
	show(head);
	change(n);
	show(head);
}