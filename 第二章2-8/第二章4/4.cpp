#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;
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
		}
		pnew->next = NULL;
		tail = pnew;
	}
	return 0;
}

void show()
{
	node*p = (node*)malloc(sizeof(node));
	p = head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}

int max()
{
	int t;
	node*p = (node*)malloc(sizeof(node));
	p = head;
	t = p->data;
	while (p->next != NULL)
	{
		if (t < p->next->data)
		{
			t = p->next->data;
		}
		p = p->next;
	}
	cout << t;
	return 0;
}

int count()
{
	int t = 0;
	node*p = (node*)malloc(sizeof(node));
	p = head;
	while (p != NULL)
	{
		t++;
		p = p->next;
	}
	cout << t;
	return t;
}

int average(int n)
{
	int sum = 0;
	node*p = (node*)malloc(sizeof(node));
	p = head;
	while (p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	cout << sum / n;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	create_list(n);
	count();
	max();
	average(n);
	return 0;
}