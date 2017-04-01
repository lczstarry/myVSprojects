#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
using namespace std;

template <class T>
class binarytreenode
{
public:
	T element;
	binarytreenode<T>*leftchild;
	binarytreenode<T>*rightchild;
public:
	binarytreenode(){}		//Ĭ�Ϲ��캯��
	binarytreenode(const T& ele)		//�����������ֵ�Ĺ��캯��
	{
		element = ele;
	}
	binarytreenode(const T& ele, binarytreenode<T>*l, binarytreenode<T>*r)		//��������ֵ�����Һ��ӽڵ�Ĺ��캯��
	{
		element = ele;
		leftchild = l;
		rightchild = r;
	}
	binarytreenode<T>*getleftchild() const		//���ظýڵ�����ӽڵ�
	{
		return leftchild;
	}
	binarytreenode<T>*getrightchild() const		//���ظýڵ���Һ��ӽڵ�
	{
		return rightchild;
	}
	void setleftchild(binarytreenode<T>*l)		//���øýڵ�����ӽڵ�
	{
		leftchild = l;
	}
	void setrightchild(binarytreenode<T>*r)		//���øýڵ���Һ��ӽڵ�
	{
		rightchild = r;
	}
	T getvalue() const		//���ظý�������ֵ
	{
		return element;
	}
	void setvalue(const T& val)		//���øý�������ֵ
	{
		element = val;
	}
	bool isleaf() const		//�жϸýڵ��Ƿ���Ҷ�ӽ�㣬���ǣ��򷵻�true
	{
		if (this->leftchild || this->rightchild)
		{
			return true;
		}
		else
			return false;
	}
};

template <class T>
class binarytree
{
public:
	binarytreenode<T>*root = NULL;		//�����������
public:
	binarytree(){};		//Ĭ�Ϲ��캯��
	~binarytree(){};		//��������
	binarytreenode<T>*find(binarytreenode<T>*treenode, T data)
	{
		binarytreenode<T>*p;
		if (treenode == NULL)
			return NULL;
		else
		{
			if (treenode->element == data)
				return treenode;
			else
			{
				if (p = find(treenode->leftchild, data))
					return p;
				else if (p = find(treenode->rightchild, data))
					return p;
				else
					return NULL;
			}
		}
	}
	binarytreenode<T>*insert(binarytreenode<T>*root, T data)
	{
		binarytreenode<T>*p = root;
		binarytreenode<T>*temp;
		binarytreenode<T>*pnew = new binarytreenode<T>(data, NULL, NULL);
		if (p == NULL)
		{
			root = new binarytreenode<T>(data, NULL, NULL);
		}
		else
		{
			while (p != NULL)
			{
				temp = p;
				if (p->element <= data)
					p = p->leftchild;
				else
					p = p->rightchild;
			}
			if (temp->element <= data)
				temp->leftchild = pnew;
			else
				temp->rightchild = pnew;
		}
		return root;
	}
	binarytreenode<T>* create()		//��һ������������
	{
		T data = 0;
		cout << "���������ݣ���0��β" << endl;
		cin >> data;
		while (data != 0)
		{
			root = insert(root, data);
			cin >> data;
		}
		return root;
	}

	bool isempty() const		//�ж϶������Ƿ�Ϊ����
	{
		if (root)
			return false;
		return true;
	}
	binarytreenode<T>*getroot() const		//���ض������ĸ��ڵ�
	{
		return root;
	}
	binarytreenode<T>*getleftsibling(binarytreenode<T>*current) const	//����current������ڵ�
	{
		return current->getleftchild();
	}
	binarytreenode<T>*getrightsibling(binarytreenode<T>*current) const	//����current�����ҽڵ�
	{
		return current->getrightchild();
	}
	void visit(binarytreenode<T>*p)
	{
		if (p)
			cout << p->element << ' ';
		else
			return;
	}
	void preorder_recusion(binarytreenode<T>*root)		//�ݹ�ʵ��
	{
		if (root)
		{
			visit(root);
			preorder_recusion(root->leftchild);
			preorder_recusion(root->rightchild);
		}
	}
	void inorder_recusion(binarytreenode<T>*root)		//�ݹ�ʵ��
	{
		if (root)
		{
			inorder_recusion(root->leftchild);
			visit(root);
			inorder_recusion(root->rightchild);
		}
	}
	void postorder_recusion(binarytreenode<T>*root)
	{
		if (root)
		{
			postorder_recusion(root->leftchild);
			postorder_recusion(root->rightchild);
			visit(root);
		}
	}
	void delete_copy(binarytreenode<T>*&node)//����ɾ��
	{
		binarytreenode<T>*pre;
		binarytreenode<T>*tmp = node;
		if (node->rightchild == NULL)
			node = node->leftchild;
		else if (node->leftchild == NULL)
			node = node->rightchild;
		else
		{
			tmp = node->leftchild;
			pre = node;
			while (tmp->rightchild != NULL)
			{
				pre = tmp;
				tmp = tmp->rightchild;
			}
			node->element = tmp->element;
			if (pre == node)
				pre->leftchild = tmp->leftchild;
			else
				pre->rightchild = tmp->rightchild;
		}
		delete tmp;
	}
	void DELETE()
	{
		cout << "����������ɾ������" << endl;
		int d;
		cin >> d;
		binarytreenode<T>*de = find(root, d);
		delete_copy(de);
	}
};

int max(int a, int b, int c)
{
	int t;
	if (a > b)
		t = a;
	else
		t = b;
	if (t > c)
		return t;
	else
		return c;
}

class binarytreenode_3
{
public:
	string element;
	int num;
	binarytreenode_3*lchild;
	binarytreenode_3*mchild;
	binarytreenode_3*rchild;
public:
	binarytreenode_3(){}		//Ĭ�Ϲ��캯��
	binarytreenode_3(const string& ele)		//�����������ֵ�Ĺ��캯��
	{
		element = ele;
	}
	binarytreenode_3(const string& ele, binarytreenode_3*l, binarytreenode_3*m, binarytreenode_3*r, int n)		//��������ֵ�����Һ��ӽڵ�Ĺ��캯��
	{
		element = ele;
		lchild = l;
		mchild = m;
		rchild = r;
		num = n;
	}
	binarytreenode_3*getleftchild() const		//���ظýڵ�����ӽڵ�
	{
		return lchild;
	}
	binarytreenode_3*getmchild() const		//���ظýڵ�����ӽڵ�
	{
		return mchild;
	}
	binarytreenode_3*getrightchild() const		//���ظýڵ���Һ��ӽڵ�
	{
		return rchild;
	}
	void setleftchild(binarytreenode_3*l)		//���øýڵ�����ӽڵ�
	{
		lchild = l;
	}
	void setmchild(binarytreenode_3*m)		//���øýڵ�����ӽڵ�
	{
		mchild = m;
	}
	void setrightchild(binarytreenode_3*r)		//���øýڵ���Һ��ӽڵ�
	{
		rchild = r;
	}
	string getvalue() const		//���ظý�������ֵ
	{
		return element;
	}
	void setvalue(const string& val)		//���øý�������ֵ
	{
		element = val;
	}
	bool isleaf() const		//�жϸýڵ��Ƿ���Ҷ�ӽ�㣬���ǣ��򷵻�true
	{
		if (this->lchild || this->mchild || this->rchild)
		{
			return true;
		}
		else
			return false;
	}
};

class binarytree_3
{
public:
	binarytreenode_3*root;
public:
	void create()
	{
		root = new binarytreenode_3("1", NULL, NULL, NULL, 10);
		root->lchild = new binarytreenode_3("2", NULL, NULL, NULL, 1);
		root->mchild = new binarytreenode_3("3", NULL, NULL, NULL, 4);
		root->lchild->lchild = new binarytreenode_3("4", NULL, NULL, NULL, 1);
		root->lchild->mchild = new binarytreenode_3("5", NULL, NULL, NULL, 2);
		root->mchild->lchild = new binarytreenode_3("6", NULL, NULL, NULL, 2);
		root->mchild->mchild = new binarytreenode_3("7", NULL, NULL, NULL, 1);
		root->mchild->lchild->lchild = new binarytreenode_3("8", NULL, NULL, NULL, 21);
		root->mchild->mchild->lchild = new binarytreenode_3("9", NULL, NULL, NULL, 5);
		root->mchild->lchild->lchild->lchild = new binarytreenode_3("10", NULL, NULL, NULL, 1);
		root->mchild->lchild->lchild->mchild = new binarytreenode_3("11", NULL, NULL, NULL, 4);
		root->mchild->lchild->lchild->rchild = new binarytreenode_3("12", NULL, NULL, NULL, 2);
		root->mchild->lchild->lchild->lchild->lchild = new binarytreenode_3("13", NULL, NULL, NULL, 1);
		root->mchild->lchild->lchild->lchild->mchild = new binarytreenode_3("14", NULL, NULL, NULL, 1);
		root->mchild->lchild->lchild->mchild->lchild = new binarytreenode_3("15", NULL, NULL, NULL, 2);
		root->mchild->lchild->lchild->mchild->mchild = new binarytreenode_3("16", NULL, NULL, NULL, 1);
	}
	void create_by_auto(binarytreenode_3* root)
	{
		string a;
		cin >> a;
		int b;
		cin >> b;
		if (a == "0")
		{
			root = NULL;
			cout << "������Ч������ָ��" << endl;
			return;
		}
		else
		{
			root = new binarytreenode_3(a, NULL, NULL, NULL, b);
		}
		cin >> a;

	}
	void postorder_transform(binarytreenode_3*root)		//�ݹ�ʵ��
	{
		if (root)
		{
			postorder_transform(root->lchild);
			postorder_transform(root->mchild);
			postorder_transform(root->rchild);
			if (root->lchild&&root->mchild&&root->rchild)
			{
				root->lchild->rchild = root->mchild;
				root->mchild->rchild = root->rchild;
				root->mchild = NULL;
				root->rchild = NULL;
			}
		}
		else
			return;
	}
	binarytreenode_3*find_now(binarytreenode_3*treenode, string data)
	{
		binarytreenode_3*p;
		if (treenode == NULL)
			return NULL;
		else
		{
			if (treenode->element == data)
				return treenode;
			else
			{
				if (p = find_now(treenode->lchild, data))
					return p;
				else if (p = find_now(treenode->mchild, data))
					return p;
				else if (p = find_now(treenode->rchild, data))
					return p;
				else
					return NULL;
			}
		}
	}
	void visit(binarytreenode_3* root)
	{
		if (root)
			cout << root->element << ' ';
		else
			return;
		visit(root->lchild);
		visit(root->mchild);
		visit(root->rchild);
	}
	void show(binarytreenode_3* root)
	{
		if (root)
		{
			cout << root->element << ' '<<endl;
			if (root->lchild)
				cout << root->lchild->element << ' ';
			if (root->mchild)
				cout << root->mchild->element << ' ';
			if (root->rchild)
				cout << root->rchild->element << ' ' << endl;
		}
		else
			return;
	}
	int height(binarytreenode_3*root)		//ͳ�Ƹ߶�
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(height(root->lchild), height(root->mchild), height(root->rchild)) + 1;
	}
	int* width(binarytreenode_3*root, int*a, int i = 0)	//ͳ�ƿ��
	{
		if (root != NULL)
		{
			a[i] = a[i] + root->num;
			width(root->lchild, a, i + 1);
			width(root->mchild, a, i + 1);
			width(root->rchild, a, i + 1);
		}
		return a;
	}
};

int main()
{
	binarytree_3 a;
	int* b;
	a.create();
	
	a.visit(a.root);
	cout << endl;
	b = new int[a.height(a.root)];
	for (int i = 0; i < a.height(a.root); i++)
	{
		b[i] = 0;
	}
	a.width(a.root, b, 0);
	for (int i = 0; i < a.height(a.root); i++)
	{
		cout << "��" << i +1<< "��Ĳ�����Ϊ" << endl;
		cout << b[i] << endl;
	}
	binarytreenode_3* p;
	p = a.find_now(a.root, "8");
	a.show(p);
	cout << endl;
	return 0;
}
