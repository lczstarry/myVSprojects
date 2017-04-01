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

void Delete(int x)
{
	node*p = (node*)malloc(sizeof(node));
	p = head;
	node*DELETE = (node*)malloc(sizeof(node));
	DELETE = NULL;
	while (p != NULL)
	{
		if (p->data == x)
		{
			if (p == head)
			{
				DELETE = p;
				head = p->next;
				p->next->prev = NULL;
				delete DELETE;
				break;
			}
			if (p == tail)
			{
				DELETE = p;
				tail = p->prev;
				p->prev->next = NULL;
				delete DELETE;
				break;
			}
			DELETE = p;
			(p->prev)->next = p->next;
			(p->next)->prev = p->prev;
			delete DELETE;
			break;
		}
		p = p->next;
	}
}

int main()
{
	int n;
	cin >> n;
	create_list(n);
	show(head);
	int x;
	cin >> x;
	Delete(x);
	show(head);
	return 0;
}