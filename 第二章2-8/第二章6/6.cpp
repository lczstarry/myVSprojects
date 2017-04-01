#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;
};

node*ha = (node*)malloc(sizeof(node));
node*tail1 = (node*)malloc(sizeof(node));
node*hb = (node*)malloc(sizeof(node));
node*tail2 = (node*)malloc(sizeof(node));
node*head = (node*)malloc(sizeof(node));

node *create_list_ha(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		node*pnew = (node*)malloc(sizeof(node));
		cin >> pnew->data;
		if (0 == i)
		{
			ha = tail1 = pnew;
		}
		else
		{
			tail1->next = pnew;
		}
		pnew->next = NULL;
		tail1 = pnew;
	}
	return 0;
}

node *create_list_hb(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		node*pnew = (node*)malloc(sizeof(node));
		cin >> pnew->data;
		if (0 == i)
		{
			hb = tail2 = pnew;
		}
		else
		{
			tail2->next = pnew;
		}
		pnew->next = NULL;
		tail2 = pnew;
	}
	return 0;
}

void guibing()
{
	node*pa = (node*)malloc(sizeof(node));
	node*pb = (node*)malloc(sizeof(node));
	node*pc = (node*)malloc(sizeof(node));
	pa = ha;
	pb = hb;
	if (pa->data < pb->data)
	{
		pc = pa;
		head = pa;
		pa = pa->next;
	}
	else
	{
		pc = pb;
		head = pb;
		pb = pb->next;
	}
	while (pa&&pb)
	{
		
		if (pa->data < pb->data)
		{
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
		}
		else
		{
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
		}
	}
	if (pa != NULL)
	{

		while (pa != NULL)
		{
			pc->next = pa;
			pa = pa->next;
			pc = pc->next;
		}
	}
	if (pb != NULL)
	{

		while (pb != NULL)
		{
			pc->next = pb;
			pb = pb->next;
			pc = pc->next;
		}
	}
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

int main()
{
	int m, n;
	cin >> n;
	create_list_ha(n);
	cin >> m;
	create_list_hb(m);
	guibing();
	show();
	return 0;
}