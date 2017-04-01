#include<iostream>
using namespace std;

class node
{
public:
	int data[5];
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
		for (int i = 0; i < 5; i++)
		{
			cin >> pnew->data[i];
		}
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

node*find(int n)
{
	node*p = (node*)malloc(sizeof(node));
	p = head;
	int j = 0;
	while (p != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			if (p->data[i] == n)
			{
				cout << j << endl;
				return p;
			}
		}
		p = p->next;
		j = j + 1;
	}
	cout << endl;
}

void show(node*p,int n)
{
	if (p != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			if (p->data[i] == n)
			{
				cout << i;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "无法找到该值" << endl;
	}
}

int main()
{
	int n, x;
	cin >> n;
	create_list(n);
	cout << "输入查找值" << endl;
	cin >> x;
	//find(x);
	show(find(x),x);
	return 0;
}
