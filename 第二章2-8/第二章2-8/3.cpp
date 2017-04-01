#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;
};

node*h = new node;
node*tail = new node;

node *create_list(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		node*pnew = new node;
		cin >> pnew->data;
		if (0 == i)
		{
			h = tail = pnew;
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

void zhuanhuan(int n)
{
	node*p1 = (node*)malloc(sizeof(node));
	node*p2 = (node*)malloc(sizeof(node));
	node*p3 = (node*)malloc(sizeof(node));


	
	p1 = h;
	p2 = p1->next;
	p3 = p2->next;//p3用来保存p2后面的链表，以免p1、p2倒置后，链表丢失。

	p1->next = NULL;

	while (p3 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}

	p2->next = p1;
	h = p2;

}

void show()
{
	node*p = new node;
	p = h;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}
int main()
{
	int n;
	cin >> n;
	create_list(n);
	zhuanhuan(n);
	show();
	return 0;
}