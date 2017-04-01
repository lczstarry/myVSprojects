#include<stdio.h> 
#include<stdlib.h> 
typedef char DataType;
typedef enum{ Link, Thread } PointerTag; //指针域是孩子还是线索的标志
typedef struct node
{
	DataType data; //数据域
	PointerTag ltag, rtag; //指针域信息的标志
	struct node * lchild, *rchild; //指针域

}BinTNode; //线索树结点
typedef BinTNode *BinTree;
BinTNode *pre = NULL; //前驱指针

void CreateBinTree(BinTree *T) //按前序建立二叉树,数据按前序输入
{
	char ch;
	if ((ch = getchar()) == ' ')
	{
		*T = NULL;
	}
	else
	{
		*T = (BinTNode*)malloc(sizeof(BinTNode));
		(*T)->data = ch;
		CreateBinTree(&(*T)->lchild);
		CreateBinTree(&(*T)->rchild);

	}

}

void InorderThreading(BinTree p) //递归函数,建立中序线索信息.注意这里有两个指针p和pre,其中pre指向p的前驱结点
{
	if (p)
	{
		InorderThreading(p->lchild);
		p->ltag = (p->lchild) ? Link : Thread;
		p->rtag = (p->rchild) ? Link : Thread;
		if (pre)
		{
			if (pre->rtag == Thread)
				pre->rchild = p;
			if (p->ltag == Thread)
				p->lchild = pre;
		}
		pre = p;
		InorderThreading(p->rchild);
	}
}

void Inorder(BinTree T) //递归方式中序遍历
{
	if (T)
	{
		Inorder(T->lchild);
		printf("%c", T->data);
		Inorder(T->rchild);

	}
}

void forder(BinTree T) //递归方式前序遍历
{
	if (T)
	{
		printf("%c", T->data);
		forder(T->lchild);
		forder(T->rchild);

	}
}

void lorder(BinTree T) //递归方式后序遍历
{
	if (T)
	{
		lorder(T->lchild);
		lorder(T->rchild);
		printf("%c", T->data);

	}
}

BinTNode * InorderSuccessor(BinTNode *p) //求p的中序后继,如果p结点的rtag域为线索,则其后继就是rchild指向结点,否则其后继是其右子树最左下结点.
{
	BinTNode *q;
	if (p->rtag == Thread)
		return p->rchild;
	else
	{
		q = p->rchild;
		while (q->ltag == Link)
			q = q->lchild;
		return q;
	}
}

BinTNode * InorderPrioror(BinTNode *p) //求p结点的前驱,如果p结点的ltag域为线索,则其前驱就是lchild指向结点,否则其前驱是其左子树最右下结点.

{
	BinTNode *q;
	if (p->ltag == Thread)
		return p->lchild;
	else
	{
		q = p->lchild;
		while (q->rtag == Link)
			q = q->rchild;
		return q;
	}
}

void TraverseInorderTree(BinTree p) //使用线索进行中序遍历,这时不需使用递归方式
{
	if (p)
	{
		while (p->ltag == Link)
			p = p->lchild;
		do
		{
			printf("%c", p->data);
			p = InorderSuccessor(p);
		} while (p);
	}
}

void main() //主函数,具体实现什么功能参考上面注释,很简单的
{
	BinTree Tree;
	BinTNode *s, *p;
	CreateBinTree(&Tree);
	forder(Tree);
	printf("\n");
	Inorder(Tree);
	printf("\n");
	lorder(Tree);
	printf("\n");
	InorderThreading(Tree);
	s = InorderSuccessor(Tree->lchild);
	printf("\noutput successor:");
	printf("%c\n", s->data);
	printf("\noutput prioror:");
	p = InorderPrioror(Tree->lchild);
	printf("%c\n", p->data);
	TraverseInorderTree(Tree);
}