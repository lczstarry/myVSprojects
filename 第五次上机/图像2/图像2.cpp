#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class T>
class MinHeap
{
private:
	T * heapArray;
	int CurrentSize;
	int MaxSize;
	void BuildHeap();
public:
	MinHeap(const int n);
	~MinHeap(){ delete[]heapArray; };
	bool isLeaf(int pos) const;
	int leftchild(int pos) const;
	int rightchild(int pos) const;
	int parent(int pos) const;
	bool Insert(T& newNode);
	T& RemoveMin();
	void SiftUp(int position);
	void SiftDown(int left);
	friend bool operator >(T & t1, T & t2);
};
template<class T>
bool operator>(T & t1, T & t2)
{
	return t1.value()> t2.value();
}
template<class T>
MinHeap<T>::MinHeap(const int n)
{
	if (n <= 0)
		return;
	CurrentSize = 0;
	MaxSize = n;
	heapArray = new T[MaxSize];
	BuildHeap();
}
template<class T>
bool MinHeap<T>::isLeaf(int pos) const
{
	return (pos >= CurrentSize / 2) && (pos<CurrentSize);
}
template<class T>
int MinHeap<T>::leftchild(int pos) const
{
	return 2 * pos + 1;
}      //返回左孩子位置
template<class T>
int MinHeap<T>::rightchild(int pos) const
{
	return 2 * pos + 2;
}      //返回右孩子位置
template<class T>
int MinHeap<T>::parent(int pos) const
{
	return (pos - 1) / 2;
}    //返回父结点位置
template <class T>
void MinHeap<T>::SiftDown(int position)
{
	int i = position;
	int j = 2 * i + 1;
	T	temp = heapArray[i];
	while (j<CurrentSize)
	{
		if ((j < CurrentSize - 1) && (heapArray[j].value() > heapArray[j + 1].value()))
			j++;
		if (temp.value()>heapArray[j].value())
		{
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;
		}
		else break;
	}
	heapArray[i] = temp;
}
template<class T>
void MinHeap<T>::BuildHeap()
{
	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
		SiftDown(i);
}
template <class T>
bool MinHeap<T>::Insert(T& newNode)
{
	if (CurrentSize == MaxSize)
		return false;
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);
	CurrentSize++;
	return true;
}
template<class T>
void MinHeap<T>::SiftUp(int position)
{
	int i = position;
	int j = parent(i);
	T temp = heapArray[i];
	while ((i>0) && (heapArray[j].value()>temp.value()))
	{

		heapArray[i] = heapArray[j];
		i = j;
		j = parent(j);

	}
	heapArray[i] = temp;
}
template<class T>
T& MinHeap<T>::RemoveMin()
{
	if (CurrentSize == 0)
	{
		cout << "Can't Delete" << endl;
		exit(1);
	}
	else
	{
		int a = CurrentSize - 1;
		T Currentnum = heapArray[a];
		T temp;
		temp = heapArray[0];
		heapArray[0] = heapArray[a];
		heapArray[a] = temp;
		CurrentSize--;
		if (a>1)
			SiftDown(0);

		return temp;
	}
}
//*********************************************************************************************
class HuffmanTree;
class HuffmanTreeNode
{
	friend class HuffmanTree;
private:
	int  element;
	char data;
	HuffmanTreeNode *left;
	HuffmanTreeNode *right;
	HuffmanTreeNode *parent;
public:
	HuffmanTreeNode(const int & ele, HuffmanTreeNode * l, HuffmanTreeNode * r, HuffmanTreeNode *p);
	int  value() const{ return element; };
	HuffmanTreeNode *  leftchild() const{ return left; }
	HuffmanTreeNode *  returnparent() const{ return right; }
	HuffmanTreeNode *  rightchild() const{ return parent; }
	bool isLeaf(){ return (this->left == NULL&&this->right == NULL); };
	bool  isLeaf() const{ return (left == NULL&& right == NULL); }
	HuffmanTreeNode(){ element = 0; data = NULL; left = right = parent = NULL; };
};
//**************************************************************************************
class HuffmanTree
{
public:
	HuffmanTreeNode * root;
	void MergeTree(HuffmanTreeNode  &ht1, HuffmanTreeNode  &ht2, HuffmanTreeNode * parent);
	HuffmanTree(int weight[], int n);
	~HuffmanTree(){};
	void Encode();
	void Bianli(HuffmanTreeNode * pTree, string str);
	void Outcode();
	void Decode();
};
void HuffmanTree::Decode()
{
	ifstream infile;
	infile.open("output1.txt", ios_base::in);
	if (!infile)
	{
		cout << "cannot open outputs.txt " << endl;
		return;
	}
	char a;
	HuffmanTreeNode* pointer = root;
	while (infile >> a)
	{
		if (a == '1')
			pointer = pointer->right;
		else if (a == '0')
			pointer = pointer->left;
		else
			return;
		if (pointer->isLeaf())
		{
			cout << pointer->data;
			pointer = root;
		}
	}
	cout << endl;
}
void HuffmanTree::Outcode()
{
	ofstream outfile;
	ifstream infile1;
	char a[128][50] = { 0 };
	infile1.open("output2.txt", ios_base::in);
	if (!infile1)
	{
		cout << "cannot open the file outs.txt" << endl;
		return;
	}
	int i = 0;
	while (infile1 >> a[i])
	{
		i++;
	}
	infile1.close();
	ifstream infile2;
	outfile.open("output1.txt", ios_base::out);
	infile2.open("input.txt", ios_base::in);
	if (!infile2)
	{
		cout << "cannot open the file input.txt" << endl;
		return;
	}
	if (!outfile)
	{
		cout << "cannot open the file outputs.txt" << endl;
		return;
	}
	char x;
	while (infile2 >> x)
	{
		for (int j = 0; j<i; j++)
		{
			if (a[j][0] == x)
			for (int w = 1; w<strlen(a[j]); w++)
				outfile << a[j][w];
		}
	}
	outfile.close();
	infile2.close();
}
HuffmanTree::HuffmanTree(int weight[], int n)
{
	MinHeap< HuffmanTreeNode > heap(n);
	HuffmanTreeNode *parent;
	HuffmanTreeNode* NodeList = new HuffmanTreeNode[n];
	int j = 0;
	for (int i = 0; i<n; i++)
	{
		if (weight[i] == 0)
			continue;
		NodeList[i].element = weight[i];
		NodeList[i].data = i;
		NodeList[i].parent = NodeList[i].left = NodeList[i].right = NULL;
		heap.Insert(NodeList[i]);
		j++;
	}
	for (int i = 0; i<j - 1; i++)
	{
		parent = new HuffmanTreeNode;
		HuffmanTreeNode *firstchild = new HuffmanTreeNode;
		HuffmanTreeNode *secondchild = new HuffmanTreeNode;
		*firstchild = heap.RemoveMin();
		*secondchild = heap.RemoveMin();
		MergeTree(*firstchild, *secondchild, parent);
		heap.Insert(*parent);
		root = parent;
	}
	delete[]NodeList;
}
void HuffmanTree::MergeTree(HuffmanTreeNode  &ht1, HuffmanTreeNode &ht2, HuffmanTreeNode * parent)
{
	parent->left = &ht1;
	parent->right = &ht2;
	parent->element = ht1.value() + ht2.value();
	parent->data = 0;
	ht1.parent = parent;
	ht2.parent = parent;
}
void HuffmanTree::Encode()            //生成哈弗曼编码
{

	string str = "";
	ofstream out;
	out.open("output2.txt", ios::out);
	out.close();
	Bianli(root, str);
}
void HuffmanTree::Bianli(HuffmanTreeNode * pTree, string str)
{
	if (pTree == NULL)
		return;
	ofstream out;
	if (pTree->isLeaf())   //是叶结点，递归结束
	{
		out.open("output2.txt", ios_base::app);
		if (!out)
		{
			cout << "error!out" << endl;
			exit(0);
		}
		out << pTree->data << str << endl;
		cout << pTree->data << "     " << str << endl;
		out.close();
		return;
	}
	//非叶结点
	string temp = str;
	str += "0";
	Bianli(pTree->left, str);
	temp += "1";
	Bianli(pTree->right, temp);
}
int main()
{
	int c = 1;
	if (c == 1)
	{
		ifstream infile;
		infile.open("input.txt", ios_base::in);
		if (!infile)
		{
			cout << "cannot open the file" << endl;
			exit(0);
		}
		char a;
		int i;
		int character[128];
		for (i = 0; i<128; i++)
			character[i] = 0;
		while (infile >> a)
		{
			character[a]++;
		}
		HuffmanTree  ht(character, 128);
		ht.Encode();
		ht.Outcode();
		ht.Decode();
	}
	return 0;
}