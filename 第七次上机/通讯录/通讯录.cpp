#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	string name;
	int telephone;
	string email;
	node *next;
};

class book
{
public:
	int number;
	node*head = new node;
	node*tail = new node;
	book(int n)
	{
		cout << "初始化通信录：" << endl;
		int i;
		number = n;
		for (i = 0; i < n; i++)
		{
			node*p = new node;
			cin >> p->name;
			cin >> p->telephone;
			cin >> p->email;
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
	void add()
	{
		cout << "输入你想插入的人名及信息：" << endl;
		node*a = new node;
		cin >> a->name;
		cin >> a->telephone;
		cin >> a->email;
		node*p = new node;
		p = head;
		if (a->name<p->name)
		{
			a->next = p;
			head = a;
			number++;
		}
		else
		{
			while (a->name > p->name)
			{
				if (p == tail)
				{
					break;
				}
				else
				{
					if (p->next->name > a->name)
					{
						break;
					}
				}
				p = p->next;
			}
			if (p != tail)
			{
				a->next = p->next;
				p->next = a;
			}
			else
			{
				p->next = a;
				tail = a;
			}
			number++;
		}
	}
	void dele()
	{
		cout << "请输入要删除的名字：" << endl;
		string s;
		cin >> s;
		node*p = new node;
		node*q = new node;
		p = head;
		q = p->next;
		if (p->name == s)
		{
			head = head->next;
			number--;
		}
		else
		{
			while (q->name != s)
			{
				if (p == tail)
				{
					cout << "查找失败" << endl;
					exit(0);
				}
				p = p->next;
				q = p->next;
			}
			if (q == tail)
			{
				tail = p;
				p->next = NULL;
				number--;
				delete q;
			}
			else
			{
				p->next = q->next;
				number--;
				delete q;
			}
		}
	}
	void change()
	{
		string newname;
		int newtel;
		string newemail;
		cout << "请输入你要修改部分的名字：" << endl;
		string s;
		cin >> s;
		node*p = new node;
		p = head;
		while (p->name != s)
		{
			p = p->next;
		}
		cin >> newname;
		cin >> newtel;
		cin >> newemail;
		p->name = newname;
		p->telephone = newtel;
		p->email = newemail;
	}

	void showfekuai()
	{
		cout << "输入你要查询的首字母：" << endl;
		char c;
		cin >> c;
		node*p = new node;
		p = head;
		while (p != NULL)
		{
			if (p->name[0] == c)
			{
				cout << "name:" << p->name << "  " << "telephone:" << p->telephone << "  " << "e-mail:" << p->email << endl;
			}
			p = p->next;
		}
		cout << endl;
	}
	void show()
	{
		node*q = new node;
		q = head;
		while (q != NULL)
		{
			for (int i = 0; i < number; i++)
			{
				cout << "name:" << q->name << "  " << "telephone:" << q->telephone << "  " << "e-mail:" << q->email << endl;
				q = q->next;
			}
		}
		cout << endl;
	}
};


class hashtable
{
public:
	node**ht;
	int maxsize;
public:
	hashtable(int size)
	{
		maxsize = size;
		ht = new node*[maxsize];
		for (int i = 0; i < maxsize; i++)
		{
			ht[i] = new node;
		}
	}
	~hashtable()
	{
		delete[]ht;
	}
	void hashputin(node*head)
	{
		int i;
		node *q = new node;
		q = head;
		while (q != NULL)
		{
			i = q->name[0] - 97;
			node *p = new node;
			while (ht[i]->name != "")
			{
				i++;
			}
			ht[i] = p;
			p->name = q->name;
			p->telephone = q->telephone;
			p->email = q->email;
			q = q->next;
		}
	}
	bool hashsearch()
	{
		string s;
		cout << "输入你要查找的人名：" << endl;
		cin >> s;
		int j = s[0] - 97;
		node*p = new node;
		p = ht[j];
		while (p != NULL)
		{
			p = ht[j];
			if (p->name == s)
			{
				cout << "散列查找成功：" << endl;
				cout << "name:" << p->name << "  " << "telephone:" << p->telephone << "  " << "e-mail:" << p->email << endl;
				return true;
			}
			j++;
		}
		cout << "查找失败。" << endl;
		return false;
	}
};



void main()
{
	book a(4);
	a.show();
	a.add();
	a.show();
	a.dele();
	a.show();
	a.change();
	a.show();
	a.showfekuai();
	hashtable h(50);
	h.hashputin(a.head);
	h.hashsearch();
}

