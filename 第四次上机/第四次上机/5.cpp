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
		if (p != NULL)
			cout << p->element << ' ';
		else
			return;
	}
	void breadthfirstorder()		//������ȱ�����rootΪ���ڵ������
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

	void du_1(binarytreenode<T>*root, int &t)		//ͳ�ƶ�������Ϊ1�Ľڵ�
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
	void du_2(binarytreenode<T>*root, int &t)		//ͳ�ƶ�������Ϊ2�Ľڵ�
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
	void du_0(binarytreenode<T>*root, int &t)		//ͳ�ƶ�������Ϊ0�Ľڵ�
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
	int height(binarytreenode<T>*root)		//ͳ�ƶ������߶�
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(height(root->leftchild), height(root->rightchild)) + 1;
	}
	int* width(binarytreenode<T>*root, int*a, int i = 0)	//ͳ�ƶ��������
	{
		if (root != NULL)
		{
			a[i]++;
  			width(root->leftchild, a, i + 1);
			width(root->rightchild, a, i + 1);
		}
		return a;
	}
	void MAX(binarytreenode<T>*root, int&t)		//����������е����ֵ
	{
		if (root != NULL)
		{
			t = max(t, root->element);
			MAX(root->leftchild, t);
			MAX(root->rightchild, t);
		}
	}
	void exchange(binarytreenode<T>*root)		//�������нڵ����Һ���
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
	void DELETE_allleft(binarytreenode<T>*&root)		//ɾ������Ҷ�ڵ�
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
	cout << "��Ϊ1�Ľڵ���" << t << endl;
	t = 0;
	a.du_2(a.root, t);
	cout << "��Ϊ2�Ľڵ���" << t << endl;
	t = 0;
	a.du_0(a.root, t);
	cout << "��Ϊ0�Ľڵ���" << t << endl;
	t = a.height(a.root);
	cout << "���ĸ߶�Ϊ" << t << endl;
	int *count = new int[t];
	int i = 0;
	memset(count, 0, t*sizeof(count));
	count = a.width(a.root, count, i);
	sort(count, count + t);
	cout << "���������Ϊ" << count[t - 1] << endl;
	t = 0;
	a.MAX(a.root, t);
	cout << "���е����ֵΪ" << t << endl;
	cout << "ת��ǰ�����Ĺ�����ȱ���" << endl;
	a.breadthfirstorder();
	cout << endl;
	a.exchange(a.root);
	cout << "ת��������Ĺ�����ȱ���" << endl;
	a.breadthfirstorder();
	cout << endl;
	cout << "ɾ��Ҷ�ڵ�֮ǰ�Ĺ���" << endl;
	a.breadthfirstorder();
	cout << endl;
	cout << "ɾ��Ҷ�ڵ�֮��Ĺ���" << endl;
	a.DELETE_allleft(a.root);
	a.breadthfirstorder();
	return 0;
}