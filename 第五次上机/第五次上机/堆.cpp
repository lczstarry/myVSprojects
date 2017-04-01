#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
using namespace std;

template <class T>
class maxheap
{
public:
	T* heaparray;							//存放堆数据的数组
	int currentsize;						//当前堆中元素数目
	int maxsize;							//堆所能容纳的最大元素数目
public:
	maxheap(T*array, int num, int max)		//构造函数
	{
		heaparray = array;
		currentsize = num;
		maxsize = max;
	}
	virtual ~maxheap(){};					//析构函数
	void buildheap();						//建堆
	bool isleaf(int pos)const;				//如果是叶节点，返回TRUE
	int leftchild(int pos)const 			//返回左孩子位置
	{
		return (pos * 2 + 1);
	}
	int rightchild(int pos)const			//返回右孩子位置
	{
		return (pos * 2 + 2);
	}
	int parent(int pos)const				//返回父节点位置
	{
		return pos / 2 - 1;
	}

	void siftdown(int left);				//筛选法函数，参数left表示开始处理的数组下标
	void siftup(int position);				//从position向上开始调整，使序列成为堆
	bool insert(const T& newnode);			//向堆中插入新元素newnode
	void movemax()							    //从堆顶移动最大值到尾部
	{
		T temp;
		temp = heaparray[0];
		heaparray[0] = heaparray[currentsize - 1];
		heaparray[currentsize - 1] = temp;
		T x;
		int i = 0;
		int pi = 2 * i + 1;
		while (pi <= currentsize)
		{
			if (heaparray[pi]<heaparray[pi + 1])
				pi++;
			if (heaparray[i]<heaparray[pi])
			{
				x = heaparray[i];
				heaparray[i] = heaparray[pi];
				heaparray[pi] = x;
			}
			i = pi;
			pi = i * 2 + 1;
		}
		
	}
	void build_by_shaixuan()
	{
		T x;
		int i = currentsize / 2 - 1;
		int pi = 2 * i;
		while (i >= 0)
		{
			if (heaparray[pi]<heaparray[pi + 1])
				pi++;
			if (heaparray[i]<heaparray[pi])
			{
				x = heaparray[i];
				heaparray[i] = heaparray[pi];
				heaparray[pi] = x;
			}
			i--;
			pi = i * 2 + 1;
		}
	}
	bool remove(int pos)                    //删除给定下标的元素
	{
		heaparray[pos] = heaparray[currentsize - 1];
		heaparray[currentsize - 1] = 0;
		currentsize--;
		buildheap();
		return true;
	}
};

template<class T>
void maxheap<T>::buildheap()
{
	for (int i = currentsize / 2 - 1; i >= 0; i--)
		siftdown(i);
}

template<class T>
void maxheap<T>::siftdown(int left)
{
	int i = left;
	int j = 2 * i + 1;
	T temp = heaparray[i];
	while (j < currentsize)
	{
		if ((j < currentsize - 1) && (heaparray[j] < heaparray[j + 1]))
			j++;
		if (temp < heaparray[j])
		{
			heaparray[i] = heaparray[j];
			i = j;
			j = 2 * j + 1;
		}
		else break;
	}
	heaparray[i] = temp;
}

template<class T>
bool maxheap<T>::insert(const T&newnode)
{
	int c = currentsize;
	heaparray[currentsize] = newnode;
	/*int i = 0;
	T temp;
	while (heaparray[c] > heaparray[i])
	{
		i = c / 2 - 1;
		temp = heaparray[c];
		heaparray[c] = heaparray[i];
		heaparray[i] = temp;
		c = i;
	}*/
	currentsize++;
	for (int i = currentsize / 2 - 1; i >= 0; i--)
		siftdown(i);
	return true;
}

void main()
{
	int a[20] = { 20, 12, 35, 15, 10, 80, 30, 17, 2, 1 };
	maxheap<int>maxh(a, 10, 10);
	maxh.buildheap();
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout<<endl;


	cout << "请输入您要插入的数" << endl;
	int t;
	cin >> t;
	maxh.insert(t);
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout<<endl;


	/*cout << "从堆顶移动最大值到尾部" << endl;
	maxh.movemax();
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout<<endl;*/


	cout << "请输入您要删除的下标" << endl;
	int u;
	cin >> u;
	maxh.remove(u);
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout << endl;
}
