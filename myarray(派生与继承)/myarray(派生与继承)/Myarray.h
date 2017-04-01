#include<iostream>
using namespace std;
class Myarray
{
public:
	int *alist;
	int length;
public:
	
	Myarray(int leng);
	~Myarray();
	void input();
	void display();
};
Myarray::Myarray(int leng)
{
	length = leng;
	alist = new int[length];

}
void Myarray::input()
{
	for (int i = 0; i < length; i++)
	{
		cin >> alist[i];
	}
}
void Myarray::display()
{
	for (int i = 0; i < length; i++)
	{
		cout << alist[i];
	}
	cout << endl;
}
Myarray::~Myarray()
{
	delete[] alist;
}
class Averarray :virtual public Myarray
{
public:
	
	Averarray(int leng) :Myarray(leng){}
	void averarray();
};
void Averarray::averarray()
{
	int E=0;
	float ave;
	for (int i = 0; i < length; i++)
	{
		E += alist[i];
	}
	ave = E / length;
	cout << ave << endl;

}
class Revarray :virtual public Myarray
{
public:
	Revarray(int leng) : Myarray(leng) {}
	void revarray();
};
void Revarray::revarray()
{
	
		int temp;
		for (int i = 0; i < length / 2; i++)
		{
			temp = alist[i];
			alist[i] = alist[length - i-1];
			alist[length - i - 1] = temp;
		}


}
class Nawarray :public Averarray, public Revarray
{
public:
	Nawarray(int leng) :Averarray(leng), Revarray(leng),Myarray(leng){}
};
