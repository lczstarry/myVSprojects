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
	binarytreenode(){}		//默认构造函数
	binarytreenode(const T& ele)		//给定数据域的值的构造函数
	{
		element = ele;
	}
	binarytreenode(const T& ele, binarytreenode<T>*l, binarytreenode<T>*r)		//给定数据值和左右孩子节点的构造函数
	{
		element = ele;
		leftchild = l;
		rightchild = r;
	}
	binarytreenode<T>*getleftchild() const		//返回该节点的左孩子节点
	{
		return leftchild;
	}
	binarytreenode<T>*getrightchild() const		//返回该节点的右孩子节点
	{
		return rightchild;
	}
	void setleftchild(binarytreenode<T>*l)		//设置该节点的左孩子节点
	{
		leftchild = l;
	}
	void setrightchild(binarytreenode<T>*r)		//设置该节点的右孩子节点
	{
		rightchild = r;
	}
	T getvalue() const		//返回该结点的数据值
	{
		return element;
	}
	void setvalue(const T& val)		//设置该结点的数据值
	{
		element = val;
	}
	bool isleaf() const		//判断该节点是否是叶子结点，若是，则返回true
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
	binarytreenode<T>*root = NULL;		//二叉树根结点
public:
	binarytree(){};		//默认构造函数
	~binarytree(){};		//析构函数
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
		binarytreenode<T>*temp=NULL;
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
				if (p->element >= data)
					p = p->leftchild;
				else
					p = p->rightchild;
			}
			if (temp->element >= data)
				temp->leftchild = pnew;
			else
				temp->rightchild = pnew;
		}
		return root;
	}
	binarytreenode<T>* create()		//建一个搜索二叉树
	{
		T data = 0;
		cout << "请输入数据，以0结尾" << endl;
		cin >> data;
		while (data != 0)
		{
			root = insert(root, data);
			cin >> data;
		}
		return root;
	}

	bool isempty() const		//判断二叉树是否为空树
	{
		if (root)
			return false;
		return true;
	}
	binarytreenode<T>*getroot() const		//返回二叉树的根节点
	{
		return root;
	}
	binarytreenode<T>*getleftsibling(binarytreenode<T>*current) const	//返回current结点的左节点
	{
		return current->getleftchild();
	}
	binarytreenode<T>*getrightsibling(binarytreenode<T>*current) const	//返回current结点的右节点
	{
		return current->getrightchild();
	}
	void visit(binarytreenode<T>*p)
	{
		if (p != NULL)
			cout << p->element << ' ';
		else
			return;
	}
	void breadthfirstorder()		//广度优先遍历以root为根节点的子树
	{
		queue<binarytreenode<T>*>nodequeue;
		binarytreenode<T>*p = root;
		if (p != NULL)
			nodequeue.push(p);
		while (!nodequeue.empty())
		{
			p = nodequeue.front();
			nodequeue.pop();
			visit(p);
			if (p->leftchild)
			{
				nodequeue.push(p->leftchild);
			}
			if (p->rightchild)
			{
				nodequeue.push(p->rightchild);
			}
		}
	}
	void preorder_recusion(binarytreenode<T>*root)		//递归实现
	{
		if (root)
		{
			visit(root);
			preorder_recusion(root->leftchild);
			preorder_recusion(root->rightchild);
		}
	}
	void inorder_recusion(binarytreenode<T>*root)		//递归实现
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
	void delete_copy(binarytreenode<T>*&node)//复制删除
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
		cout << "请输入您想删除的数" << endl;
		int d;
		cin >> d;
		binarytreenode<T>*de = find(root, d);
		delete_copy(de);
	}

	void du_1(binarytreenode<T>*root, int &t)		//统计二叉树度为1的节点
	{
		if ((root->leftchild == NULL&&root->rightchild != NULL) || (root->leftchild != NULL&&root->rightchild == NULL))
		{
			t++;
		}
		if (root->leftchild != NULL)
			du_1(root->leftchild, t);
		if (root->rightchild != NULL)
			du_1(root->rightchild, t);
	}
	void du_2(binarytreenode<T>*root, int &t)		//统计二叉树度为2的节点
	{
		if (root->leftchild != NULL&&root->rightchild != NULL)
		{
			t++;
		}
		if (root->leftchild != NULL)
			du_2(root->leftchild, t);
		if (root->rightchild != NULL)
			du_2(root->rightchild, t);
	}
	void du_0(binarytreenode<T>*root, int &t)		//统计二叉树度为0的节点
	{
		if (root->leftchild == NULL&&root->rightchild == NULL)
		{
			t++;
		}
		if (root->leftchild != NULL)
			du_0(root->leftchild, t);
		if (root->rightchild != NULL)
			du_0(root->rightchild, t);
	}
	int height(binarytreenode<T>*root)		//统计二叉树高度
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(height(root->leftchild), height(root->rightchild)) + 1;
	}
	int* width(binarytreenode<T>*root, int*a, int i = 0)	//统计二叉树宽度
	{
		if (root != NULL)
		{
			a[i]++;
  			width(root->leftchild, a, i + 1);
			width(root->rightchild, a, i + 1);
		}
		return a;
	}
	void MAX(binarytreenode<T>*root, int&t)		//计算二叉树中的最大值
	{
		if (root != NULL)
		{
			t = max(t, root->element);
			MAX(root->leftchild, t);
			MAX(root->rightchild, t);
		}
	}
	void exchange(binarytreenode<T>*root)		//交换所有节点左右孩子
	{
		if (root != NULL)
		{
			binarytreenode<T>*pnew;
			pnew = root->leftchild;
			root->leftchild = root->rightchild;
			root->rightchild = pnew;
			exchange(root->leftchild);
			exchange(root->rightchild);
		}
	}
	void DELETE_allleft(binarytreenode<T>*&root)		//删除所有叶节点
	{
		if (root->leftchild == NULL&&root->rightchild == NULL)
		{
			binarytreenode<T>*node = root;
			delete node;
			root = NULL;
		}
		else
		{
			if (root->leftchild != NULL)
				DELETE_allleft(root->leftchild);
			if (root->rightchild != NULL)
				DELETE_allleft(root->rightchild);
		}
	}
};

int main()
{
	binarytree<int> a;
	a.create();
	int t = 0;
	a.du_1(a.root, t);
	cout << "度为1的节点有" << t << endl;
	t = 0;
	a.du_2(a.root, t);
	cout << "度为2的节点有" << t << endl;
	t = 0;
	a.du_0(a.root, t);
	cout << "度为0的节点有" << t << endl;
	t = a.height(a.root);
	cout << "树的高度为" << t << endl;
	int *count = new int[t];
	int i = 0;
	memset(count, 0, t*sizeof(count));
	count = a.width(a.root, count, i);
	sort(count, count + t);
	cout << "树的最大宽度为" << count[t - 1] << endl;
	t = 0;
	a.MAX(a.root, t);
	cout << "树中的最大值为" << t << endl;
	cout << "转换前的树的广度优先遍历" << endl;
	a.breadthfirstorder();
	cout << endl;
	a.exchange(a.root);
	cout << "转换后的树的广度优先遍历" << endl;
	a.breadthfirstorder();
	cout << endl;
	cout << "删除叶节点之前的广搜" << endl;
	a.breadthfirstorder();
	cout << endl;
	cout << "删除叶节点之后的广搜" << endl;
	a.DELETE_allleft(a.root);
	a.breadthfirstorder();
	return 0;
}