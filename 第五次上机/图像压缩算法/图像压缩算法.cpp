#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<Windows.h> 

using namespace std;

class Map
{
public:
	int color;
	double rate;
	string code;

	Map(int color = 0, double rate = 1, string code = "")
	{
		this->color = color;
		this->rate = rate;
		this->code = code;
	}
};

class HuffmanNode
{
public:
	int data;
	double weight;
	HuffmanNode * left;
	HuffmanNode * right;

	HuffmanNode(int data = 0, double weight = 0, HuffmanNode * left = NULL, HuffmanNode * right = NULL)
	{
		this->data = data;
		this->weight = weight;
		this->left = left;
		this->right = right;
	}

	HuffmanNode(HuffmanNode * &hNode)
	{
		this->data = hNode->data;
		this->weight = hNode->weight;
		this->left = hNode->left;
		this->right = hNode->right;
	}
};

class MinHeap
{
public:
	HuffmanNode ** huffmanNode; // 堆数组
	int currentSize; // 当前堆数组长度
	int maxSize; // 堆数组最大长度

	MinHeap(HuffmanNode ** hnode, int num, int Max); // 构造函数
	~MinHeap();
	void BuildHeap(); // 构造堆
	void Display(); // 输出
	bool IsLeaf(int pos); // 是否是叶子节点
	int LeftChild(int pos); // 返回左孩子
	int RightChild(int pos); // 返回右孩子
	int Parent(int pos); // 返回父亲节点
	void Swap(HuffmanNode * &a, HuffmanNode * &b); // 交换元素
	HuffmanNode * & RemoveMin(); // 删除根元素
	void SiftDown(int pos); // 向下筛选
	void SiftUp(int pos); // 向上筛选
	void Insert(HuffmanNode * &hNode); // 插入新元素
};

MinHeap::MinHeap(HuffmanNode ** hNode, int num, int max)
{
	maxSize = max;
	currentSize = num;
	huffmanNode = new HuffmanNode *[maxSize];
	for (int i = 0; i<currentSize; i++)
		huffmanNode[i] = hNode[i];
	huffmanNode[currentSize] = new HuffmanNode(-1, 1);
}

MinHeap::~MinHeap()
{
	for (int i = 0; i <= currentSize; i++)
		delete huffmanNode[i];
}

void MinHeap::Display()
{
	for (int i = 0; i<currentSize; i++)
		cout << huffmanNode[i]->data << " , " << huffmanNode[i]->weight << endl;
	cout << endl;
}

bool MinHeap::IsLeaf(int pos)
{
	return (2 * pos + 1 >= currentSize);
}

int MinHeap::LeftChild(int pos)
{
	if (2 * pos + 1 < currentSize)
		return (2 * pos + 1);
	else
		return currentSize;
}

int MinHeap::RightChild(int pos)
{
	if (2 * pos + 2 < currentSize)
		return (2 * pos + 2);
	else
		return currentSize;
}

int MinHeap::Parent(int pos)
{
	return ((pos - 1) / 2);
}

void MinHeap::Swap(HuffmanNode * &a, HuffmanNode * &b)
{
	HuffmanNode * temp;
	temp = a;
	a = b;
	b = temp;
}

void MinHeap::SiftDown(int pos)
{
	while (true)
	{
		if (IsLeaf(pos)) break;
		double minValue = (huffmanNode[LeftChild(pos)]->weight < huffmanNode[RightChild(pos)]->weight ?
			huffmanNode[LeftChild(pos)]->weight : huffmanNode[RightChild(pos)]->weight);
		int minPos = (huffmanNode[LeftChild(pos)]->weight < huffmanNode[RightChild(pos)]->weight ?
			LeftChild(pos) : RightChild(pos));
		if (minValue < huffmanNode[pos]->weight)
		{
			Swap(huffmanNode[pos], huffmanNode[minPos]);
			pos = minPos;
			continue;
		}
		else
			break;
	}
}

void MinHeap::BuildHeap()
{
	int start = currentSize / 2 - 1;
	for (int i = start; i >= 0; i--)
	{
		SiftDown(i);
	}
}

HuffmanNode * & MinHeap::RemoveMin()
{
	Swap(huffmanNode[0], huffmanNode[currentSize - 1]);
	currentSize--;
	HuffmanNode * temp;
	temp = new HuffmanNode(huffmanNode[currentSize]->data, huffmanNode[currentSize]->weight,
		huffmanNode[currentSize]->left, huffmanNode[currentSize]->right);
	huffmanNode[currentSize]->data = -1;
	huffmanNode[currentSize]->weight = 1;
	delete huffmanNode[currentSize + 1];
	SiftDown(0);
	return temp;
}

void MinHeap::SiftUp(int pos)
{
	while (pos > 0)
	{
		if (huffmanNode[pos]->weight < huffmanNode[Parent(pos)]->weight)
		{
			Swap(huffmanNode[pos], huffmanNode[Parent(pos)]);
			pos = Parent(pos);
		}
		else
			break;
	}
}

void MinHeap::Insert(HuffmanNode * &hNode)
{
	if (currentSize + 1 <= maxSize)
	{
		delete huffmanNode[currentSize];
		huffmanNode[currentSize] = hNode;
		huffmanNode[currentSize + 1] = new HuffmanNode(-1, 1);
		SiftUp(currentSize++);
	}
}


class HuffmanTree
{
public:
	HuffmanNode * root;
	Map * map;
	int length;
	string temp;
	string code;

	HuffmanTree(int length);
	void DFSSearch(HuffmanNode * root);
	void ProduceCode(Map *&map);
};

HuffmanTree::HuffmanTree(int length)
{
	this->length = length;
	this->temp = "";
}

void HuffmanTree::DFSSearch(HuffmanNode*root)
{
	if (root->left&&root->right)
	{
		string t = temp;
		temp += '0';
		DFSSearch(root->left);
		temp = t;
		temp += '1';
		DFSSearch(root->right);
		temp = t;
	}
	else
	{
		int pos;
		for (int i = 0; i<length; i++)
		{
			if (map[i].color == root->data)
			{
				pos = i;
				map[i].code = temp;
			}
		}
		temp = "";
	}
}

void HuffmanTree::ProduceCode(Map*&map)
{
	HuffmanNode**huffmannode;
	this->map = new Map[length];
	for (int i = 0; i<length; i++)
	{
		this->map[i].color = map[i].color;
		this->map[i].rate = map[i].rate;
	}
	huffmannode = new HuffmanNode*[length];
	for (int i = 0; i<length; i++)
	{
		huffmannode[i] = new HuffmanNode(this->map[i].color, this->map[i].rate);
	}
	MinHeap minheap(huffmannode, length, 256);
	minheap.BuildHeap();
	for (int i = 0; i<length - 1; i++)
	{
		HuffmanNode *h1, *h2;
		h1 = minheap.RemoveMin();
		h2 = minheap.RemoveMin();
		HuffmanNode * t = new HuffmanNode(256, h1->weight + h2->weight, h1, h2);
		minheap.Insert(t);
	}
	root = minheap.RemoveMin();
	DFSSearch(root);
	for (int i = 0; i<length; i++)
	{
		map[i].code = this->map[i].code;
	}
}

class Compressor
{
public:
	int * Picture;
	int * ColorScr;
	int height;
	int length;
	Map * map;
	int Num;
	string FinalCode;
public:
	Compressor();
	void Static();
	void GetPicture();
};

Compressor::Compressor()
{
	FinalCode = "";
	length = 0;
	Picture = new int[100000000];         //建立图的数据数组
	GetPicture();                           //得到图的数据
	ColorScr = new int[256];              //256种色素
	for (int i = 0; i<256; i++)
		ColorScr[i] = 0;                   //初始化
	map = new Map[256];                    //256种颜色
	Num = 0;                                  //初始化
}

int Pow(int a, int b)                       //
{
	int res = 1;
	for (int i = 0; i<b; i++)
	{
		res *= a;
	}
	return res;
}

void Compressor::GetPicture()
{
	string source = "";
	ifstream inobj("E:\\data.txt");
	while (!inobj.eof())
	{
		inobj >> source;
	}
	inobj.close();
	cout << "OK  " << source.length() / 8 << endl;
	int num = 0, scr = 0;
	for (int i = 0; i<source.length(); i++)
	{
		if ((scr + 1) % 9 == 0)
		{
			scr = 0;
			Picture[length++] = num;
			num = 0;
		}
		num += Pow(2, 7 - scr)*(int)(source[i] - '0');
		scr++;
	}
}

void Compressor::Static()
{
	for (int i = 0; i<length; i++)
	{
		ColorScr[Picture[i]] ++;
	}
	for (int i = 0; i<256; i++)
	{
		if (ColorScr[i] != 0)
		{
			map[Num].color = i;
			map[Num].rate = ColorScr[i] / (1.0*length);
			Num++;
		}
	}

	HuffmanTree hfmTree(Num);
	hfmTree.ProduceCode(map);
	cout << "\n灰度值对应的编码为：" << endl;
	for (int i = 0; i<Num; i++)
		cout << map[i].color << " : " << map[i].code << endl;
	for (int i = 0; i<length; i++)
	{
		for (int k = 0; k<256; k++)
		{
			if (map[k].color == Picture[i])
				FinalCode += map[k].code;
		}
	}

	ofstream outobj("E:\\result.txt");
	outobj << FinalCode << endl;
}

class DeCompressor
{
public:
	string TargetCode;
	int * Picture;
	int length;
	int height;
	int Num;
	Map * map;
	int * sign;

	DeCompressor(Map * map, int length, int Num);
	void Translate();
};

DeCompressor::DeCompressor(Map * map, int length, int Num)
{
	this->Num = Num;
	this->map = new Map[Num];
	this->sign = new int[Num];
	this->Picture = new int[10000000];
	this->TargetCode = "";
	ifstream inp("E:\\result.txt");
	while (!inp.eof())
	{
		inp >> this->TargetCode;
	}
	inp.close();
	inp.close();
	this->length = length;
	for (int i = 0; i<Num; i++)
	{
		sign[i] = 1;
		this->map[i].color = map[i].color;
		this->map[i].code = map[i].code;
		//cout << map[i].color << "," << map[i].code << endl ;
	}
}

void DeCompressor::Translate()
{
	int k = 0;
	int num = 0;
	//fstream output("E:\\picture.txt");
	for (int i = 0; i<TargetCode.length(); i++)
	{
		//cout << "'" << TargetCode[i] <<"'"<< endl ;
		//for(int j=0 ; j<Num ; j++)
		//cout << sign[j] << "," ;
		//cout << endl ;
		for (int j = 0; j<Num; j++)
		{
			if (sign[j] != 1) continue;
			if (k == map[j].code.length() - 1 && map[j].code[k] == TargetCode[i])
			{
				k = -1;
				Picture[num++] = map[j].color;
				cout << map[j].color << " ";
				for (int l = 0; l<Num; l++)
					sign[l] = 1;
				break;
			}
			if (TargetCode[i] != map[j].code[k])
			{
				sign[j] = 0;
			}
		}
		k++;
	}/*
	 for(int i=0 ; i<num ; i++)
	 {
	 cout << Picture[i] << "  " << endl ;
	 }
	 delete [] Picture ;*/
}

void main()
{
	cout << "原图为：" << endl;
	Compressor cmp;
	cmp.Static();
	DeCompressor dcmp(cmp.map, cmp.length, cmp.Num);
	cout << "\n解压后的图片为:" << endl;
	dcmp.Translate();
}
