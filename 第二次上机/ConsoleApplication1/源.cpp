#include<iostream>
using namespace std;

class ArrayQueue
{
private:
	int maxSize;
	int front;
	int rear;
	int *queue;
	int tag;
public:
	ArrayQueue(){};
	ArrayQueue(int size)
	{
		maxSize = size + 1;
		queue = new int[maxSize];
		front = rear = tag = 0;
	}

	bool EnQueue(const int item)
	{
		if (rear == front&&tag == 1)
		{
			cout << "�������������" << endl;
			return false;
		}
		queue[rear] = item;
		rear = rear + 1;
		tag = 1;
		return true;
	}
	bool DeQueue(int & item)
	{
		if (tag == 0)
		{
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = queue[front];
		front = front + 1;
		if (front == rear)
		{
			tag = 0;
		}
		return true;
	}
};

int main
{
	ArrayQueue A(3);
}