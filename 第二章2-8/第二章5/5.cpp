#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node*next;
};

node*A = (node*)malloc(sizeof(node));
node*tail1 = (node*)malloc(sizeof(node));
node*B = (node*)malloc(sizeof(node));
node*tail2 = (node*)malloc(sizeof(node));
node*C = (node*)malloc(sizeof(node));
node*tail3 = (node*)malloc(sizeof(node));

node *create_list1(int n, node*head, node*tail)
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
	return head;
}

void show(node*head, int n)
{
	int i;
	cout << endl;
	node*p = (node*)malloc(sizeof(node));
	p = head;
	for (i = 0; i <= n; i++)
	{
		p = p->next;
		cout << p->data << endl;
	}
}

void guibing()
{
	node*pa = (node*)malloc(sizeof(node));
	node*pb = (node*)malloc(sizeof(node));
	node*pc = (node*)malloc(sizeof(node));
	pa = A;
	pb = B;
	pc = C;
	while (pa&&pb)
	{
		node*pnew = (node*)malloc(sizeof(node));
		if (pa->data < pb->data)
		{
			pnew->data = pa->data;
			pc->next = pnew;
			pc = pc->next;
			pa = pa->next;
		}
		else
		{
			pnew->data = pb->data;
			pc->next = pnew;
			pc = pc->next;
			pb = pb->next;
		}
	}
	if (pa != NULL)
	{
		while (pa != NULL)
		{
			node*pnew = (node*)malloc(sizeof(node));
			pnew->data = pa->data;
			pc->next = pnew;
			pc = pc->next;
			pa = pa->next;
		}
	}
	if (pb != NULL)
	{
		while (pb != NULL)
		{
			node*pnew = (node*)malloc(sizeof(node));
			pnew->data = pb->data;
			pc->next = pnew;
			pc = pc->next;
			pb = pb->next;
		}
	}
}

void zhuanhuan(int n)
{
	int t;
	int i, j;
	node*p = (node*)malloc(sizeof(node));
	p = C->next;
	for (i = 0; i <= n - 1; i++)
	{
		p = C->next;
		for (j = 0; j <= n - i - 1; j++)
		{
			t = p->data;
			p->data = p->next->data;
			p->next->data = t;
			p = p->next;
		}
	}
}

int main()
{
	int m, n;
	cin >> n;
	A = create_list1(n, A, tail1);
	cin >> m;
	B = create_list1(m, B, tail2);
	guibing();
	zhuanhuan(m + n - 1);
	show(C, m + n - 1);
	return 0;
}