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
		maxSize = size;
		queue = new int[maxSize];
		front = rear = tag=0;
	}

	bool EnQueue(const int item)
	{
		if (rear == front&&tag==1)
		{
			cout << "队列已满，溢出"<<endl;
			return false;
		}
		queue[rear] = item;
		rear = (rear + 1)%maxSize;
		tag = 1;
		return true;
	}
	bool DeQueue(int & item)
	{
		if (tag == 0)
		{
			cout << "队列为空" << endl;
			return false;
		}
		item = queue[front];
		front = (front + 1)%maxSize;
		if (front == rear)
		{
			tag = 0;
		}
		return true;
	}
};
int main()
{
	ArrayQueue A(3);
	A.EnQueue(1);
	A.EnQueue(2);
	A.EnQueue(3);
	A.EnQueue(4);
	return 0;
}
