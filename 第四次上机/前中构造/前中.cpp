/*      一个前序遍历序列和一个中序遍历序列可以确定一颗唯一的二叉树。
根据前序遍历的特点, 知前序序列(PreSequence)的首个元素(PreSequence[0])为二叉树的根(root), 然后在中序序列(InSequence)中查找此根(root),
根据中序遍历特点, 知在查找到的根(root) 前边的序列为根的左子树的中序遍历序列, 后边的序列为根的右子树的中序遍历序列。 
设在中序遍历序列(InSequence)根前边有left个元素.则在前序序列(PreSequence)中, 
紧跟着根(root)的left个元素序列(即PreSequence[1...left]) 为根的左子树的前序遍历序列, 
在后边的为根的右子树的前序遍历序列.而构造左子树问题其实跟构造整个二叉树问题一样，
只是此时前序序列为PreSequence[1...left]), 中序序列为InSequence[0...left - 1], 分别为原序列的子串, 构造右子树同样, 
显然可以用递归方法解决。

*/


#include <string>
#include <iostream>

using namespace std;

//二叉链表表示二叉树
typedef struct BiNode
{
	char data;//节点数据
	struct BiNode * lchild;//左孩子
	struct BiNode * rchild;//右孩子
}BiNode, *BiTree;

//由前序序列和中序序列建立二叉树的过程
void CreateBiTree(BiTree & t, string presequence, string insequence)//t为要建立的二叉树,presequence和insequence分别为前序和中序序列
{
	if (presequence.length() == 0)
	{
		t = NULL;
		return;
	}
	char rootNode = presequence[0];//根
	int index = insequence.find(rootNode);//根在中序序列中的位置
	string lchild_insequence = insequence.substr(0, index);//左孩子的中序序列
	string rchild_insequence = insequence.substr(index + 1);//右孩子的中序序列
	int lchild_length = lchild_insequence.length();//左孩子的长度
	int rchild_length = rchild_insequence.length();//右孩子的长度
	string lchild_presequence = presequence.substr(1, lchild_length);//左孩子的前序序列
	string rchild_presequence = presequence.substr(1 + lchild_length);//右孩子的前序序列

	t = (BiTree)malloc(sizeof(BiNode));
	if (t != NULL)
	{
		t->data = rootNode;
		CreateBiTree(t->lchild, lchild_presequence, lchild_insequence);//递归创建左孩子
		CreateBiTree(t->rchild, rchild_presequence, rchild_insequence);//递归创建右孩子
	}
}

//检验是否创建成功 
//递归前序遍历二叉树
void PreOrderTraverse(BiTree & t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
}

//递归中序序遍历二叉树
void InOrderTraverse(BiTree & t)
{
	if (t != NULL)
	{

		InOrderTraverse(t->lchild);
		cout << t->data;
		InOrderTraverse(t->rchild);
	}
}

int main()
{
	BiTree t;
	string presequence = "ABCDEFG";
	string insequence = "CBEDAFG";
	CreateBiTree(t, presequence, insequence);

	PreOrderTraverse(t);
	cout << endl;
	InOrderTraverse(t);
	system("PAUSE");
	return 0;
}
