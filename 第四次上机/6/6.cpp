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

	bool if_perfect(binarytreenode<T>*root)
	{
		if (root == NULL)
			return true;
		queue<binarytreenode<T>*>qu;
		qu.push(root);
		bool last = false;
		bool is_perfect = true;
		binarytreenode<T>*p;
		while (!qu.empty())
		{
			p = qu.front();
			qu.pop();
			if (!last)
			{
				if (p->leftchild != NULL&&p->rightchild != NULL)
				{
					qu.push(p->leftchild);
					qu.push(p->rightchild);
				}
				else if (p->leftchild != NULL&&p->rightchild == NULL)
				{
					last = true;
					qu.push(p->leftchild);
					break;
				}
				else if (p->leftchild == NULL&&p->rightchild != NULL)
				{
					last = true;
					is_perfect = false;
					break;
				}
				else
				{
					last = true;
				}
			}
			else
			{
				if (p->leftchild != NULL || p->rightchild != NULL)
				{
					is_perfect = false;
					break;
				}
			}
		}
		return is_perfect;
	}
};

int main()
{
	binarytree<int> a;
	a.create();
	int t = 0;
	if (a.if_perfect(a.root))
		cout << "该树为完全二叉树" << endl;
	else
		cout << "该树不是完全二叉树" << endl;
	return 0;
}