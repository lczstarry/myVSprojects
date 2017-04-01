#include<stdio.h> 
#include<stdlib.h> 
typedef char DataType;
typedef enum{ Link, Thread } PointerTag; //ָ�����Ǻ��ӻ��������ı�־
typedef struct node
{
	DataType data; //������
	PointerTag ltag, rtag; //ָ������Ϣ�ı�־
	struct node * lchild, *rchild; //ָ����

}BinTNode; //���������
typedef BinTNode *BinTree;
BinTNode *pre = NULL; //ǰ��ָ��

void CreateBinTree(BinTree *T) //��ǰ����������,���ݰ�ǰ������
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

void InorderThreading(BinTree p) //�ݹ麯��,��������������Ϣ.ע������������ָ��p��pre,����preָ��p��ǰ�����
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

void Inorder(BinTree T) //�ݹ鷽ʽ�������
{
	if (T)
	{
		Inorder(T->lchild);
		printf("%c", T->data);
		Inorder(T->rchild);

	}
}

void forder(BinTree T) //�ݹ鷽ʽǰ�����
{
	if (T)
	{
		printf("%c", T->data);
		forder(T->lchild);
		forder(T->rchild);

	}
}

void lorder(BinTree T) //�ݹ鷽ʽ�������
{
	if (T)
	{
		lorder(T->lchild);
		lorder(T->rchild);
		printf("%c", T->data);

	}
}

BinTNode * InorderSuccessor(BinTNode *p) //��p��������,���p����rtag��Ϊ����,�����̾���rchildָ����,�����������������������½��.
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

BinTNode * InorderPrioror(BinTNode *p) //��p����ǰ��,���p����ltag��Ϊ����,����ǰ������lchildָ����,������ǰ�����������������½��.

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

void TraverseInorderTree(BinTree p) //ʹ�����������������,��ʱ����ʹ�õݹ鷽ʽ
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

void main() //������,����ʵ��ʲô���ܲο�����ע��,�ܼ򵥵�
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