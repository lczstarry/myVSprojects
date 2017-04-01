#include<iostream>
#include<stdio.h>
#include<time.h>
#include<windows.h>
using namespace std;
class BankWindow
{
public:
	bool isBusy;
};
class LinkNode
{
public:
	int id;
	int type;
	int ServeTime;
	LinkNode *link;
	LinkNode(int n, int t, LinkNode *l) :id(n), type(t), link(NULL), ServeTime(4){};
};
class LinkQueue
{
public:
	int size;
	LinkNode *front, *rear;
	LinkQueue()
	{
		size = 0;
		front = rear = NULL;
	}
	~LinkQueue()
	{
		Clear();
	}
	void Clear()
	{
		while (front != NULL)
		{
			rear = front;
			front = front->link;
			delete rear;
		}
		rear = NULL;
		size = 0;
	}
	void EnQueue(int n, int t)
	{
		if (rear == NULL)
		{
			front = rear = new LinkNode(n, t, NULL);
		}
		else
		{
			rear->link = new LinkNode(n, t, NULL);
			rear = rear->link;
		}
		size++;
	}
	int DeQueue()
	{
		int item;
		LinkNode *temp;
		if (size == 0)
		{
			cout << "队列为空" << endl;
			exit(1);
			return -1;
		}
		else
		{
			item = front->id;
			temp = front;
			front = front->link;
			delete temp;
			size--;
			return item;
		}
	}
	int GetFront()
	{
		int item;
		if (size == 0)
		{
			cout << "队列为空" << endl;
		}
		else
		{
			item = front->id;
		}
	}
	void Show()
	{
		LinkNode *head = front;
		while (head != NULL)
		{
			cout << head->id << ' ';
			head = head->link;
		}
		cout << endl;
	}
	int GetServed();
};
int LinkQueue::GetServed()
{
	front->ServeTime--;
	if (front->ServeTime == 0)
	{
		Sleep(20);//暂停20 毫秒
		return DeQueue();
	}
	else
	{
		Sleep(20);
		return NULL;
	}
}
class Simulater
{
private:
	LinkQueue NomalUser, VIPUser, OfficalUser;
	BankWindow NomalWindow, VIPWindow, OfficalWindow;
public:
	void PaiDui();
	void nGetServed();
};
void Simulater::nGetServed()
{
	int a, b, c;
	while (NomalUser.front != NULL || VIPUser.front != NULL || OfficalUser.front != NULL)
	{
		if (NomalUser.front != NULL)
		{
			NomalWindow.isBusy = 1;
			a = NomalUser.GetServed();
			if (a)
			{
				cout << " 第" << a << "位普通用户服务完毕" << endl;
			}
		}
		else
		{
			NomalWindow.isBusy = 0;
		}
		if (VIPUser.front != NULL)
		{
			VIPWindow.isBusy = 1;
			b = VIPUser.GetServed();
			if (b)
			{
				cout << " 第" << b << "位VIP户服务完毕" << endl;
			}
		}
		else
		{
			VIPWindow.isBusy = 0;
		}
		if (OfficalUser.front != NULL)
		{
			OfficalWindow.isBusy = 1;
			c = OfficalUser.GetServed();
			if (c)
			{
				cout << " 第" << c << "位Offical用户服务完毕" << endl;
			}
		}
		else
		{
			OfficalWindow.isBusy = 0;
		}
		if (!OfficalWindow.isBusy&&NomalUser.front != NULL)
		{
			a = NomalUser.GetServed();
			if (a)
			{
				cout << " 第" << a << "位普通用户服务完毕" << endl;
			}
		}
		if (!VIPWindow.isBusy&&NomalUser.front != NULL)
		{
			a = NomalUser.GetServed();
			if (a)
			{
				cout << " 第" << a << "位普通用户服务完毕" << endl;
			}
		}
	}
}
void Simulater::PaiDui()
{
	int id1 = 1, id2 = 1, id3 = 1, temp;
	srand(time(0));
	for (int i = 0; i<100; i++)
	{
		temp = rand() % 5 + 1;//通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
		//cout<<temp<<endl;
		if (temp == 1 || temp == 2 || temp == 3)
		{
			NomalUser.EnQueue(id1, 1);
			id1++;
		}
		else if (temp == 4)
		{
			VIPUser.EnQueue(id2, 2);
			id2++;
		}
		else if (temp == 5)
		{
			OfficalUser.EnQueue(id3, 3);
			id3++;
		}
	}
	NomalUser.Show();
	VIPUser.Show();
	OfficalUser.Show();
}
int main()
{

	Simulater a;
	a.PaiDui();
	a.nGetServed();
	return 0;
}