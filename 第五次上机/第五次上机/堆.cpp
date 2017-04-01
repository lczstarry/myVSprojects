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
	T* heaparray;							//��Ŷ����ݵ�����
	int currentsize;						//��ǰ����Ԫ����Ŀ
	int maxsize;							//���������ɵ����Ԫ����Ŀ
public:
	maxheap(T*array, int num, int max)		//���캯��
	{
		heaparray = array;
		currentsize = num;
		maxsize = max;
	}
	virtual ~maxheap(){};					//��������
	void buildheap();						//����
	bool isleaf(int pos)const;				//�����Ҷ�ڵ㣬����TRUE
	int leftchild(int pos)const 			//��������λ��
	{
		return (pos * 2 + 1);
	}
	int rightchild(int pos)const			//�����Һ���λ��
	{
		return (pos * 2 + 2);
	}
	int parent(int pos)const				//���ظ��ڵ�λ��
	{
		return pos / 2 - 1;
	}

	void siftdown(int left);				//ɸѡ������������left��ʾ��ʼ����������±�
	void siftup(int position);				//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	bool insert(const T& newnode);			//����в�����Ԫ��newnode
	void movemax()							    //�ӶѶ��ƶ����ֵ��β��
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
	bool remove(int pos)                    //ɾ�������±��Ԫ��
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


	cout << "��������Ҫ�������" << endl;
	int t;
	cin >> t;
	maxh.insert(t);
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout<<endl;


	/*cout << "�ӶѶ��ƶ����ֵ��β��" << endl;
	maxh.movemax();
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout<<endl;*/


	cout << "��������Ҫɾ�����±�" << endl;
	int u;
	cin >> u;
	maxh.remove(u);
	for (int i = 0; i < maxh.currentsize; i++)
	cout << maxh.heaparray[i] << ' ';
	cout << endl;
}
