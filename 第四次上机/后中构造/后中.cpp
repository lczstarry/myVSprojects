#include <string>
#include <iostream>

using namespace std;

//���������ʾ������
typedef struct BiNode
{
	char data;//�ڵ�����
	struct BiNode * lchild;//����
	struct BiNode * rchild;//�Һ���
}BiNode, *BiTree;

//�ɺ������к��������н����������Ĺ���
void CreateBiTree(BiTree & t, string postsequence, string insequence)//tΪҪ�����Ķ�����,postsequence��insequence�ֱ�Ϊ�������������
{
	if (postsequence.length() == 0)
	{
		t = NULL;
		return;
	}
	int l= postsequence.length();//������ʽ�ĳ��� 
	char rootNode = postsequence[l-1];//��
	int index = insequence.find(rootNode);//�������������е�λ��
	string lchild_insequence = insequence.substr(0, index);//���ӵ���������
	string rchild_insequence = insequence.substr(index + 1);//�Һ��ӵ���������
	int lchild_length = lchild_insequence.length();//���ӵĳ���
	int rchild_length = rchild_insequence.length();//�Һ��ӵĳ���
	string lchild_postsequence = postsequence.substr(0, lchild_length);//���ӵĺ�������
	string rchild_postsequence = postsequence.substr( lchild_length, l - 1 - lchild_length);//�Һ��ӵĺ�������

	t = (BiTree)malloc(sizeof(BiNode));
	if (t != NULL)
	{
		t->data = rootNode;
		CreateBiTree(t->lchild, lchild_postsequence, lchild_insequence);//�ݹ鴴������
		CreateBiTree(t->rchild, rchild_postsequence, rchild_insequence);//�ݹ鴴���Һ���
	}
}

//�����Ƿ񴴽��ɹ� 
//�ݹ�ǰ�����������
void PreOrderTraverse(BiTree & t)
{
	if (t != NULL)
	{
		cout << t->data;
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
}

//�ݹ����������������
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
	string postsequence = "CEDBGFA";
	string insequence = "CBEDAFG";
	CreateBiTree(t, postsequence, insequence);

	PreOrderTraverse(t);
	cout << endl;
	InOrderTraverse(t);
	system("PAUSE");
	return 0;
}
