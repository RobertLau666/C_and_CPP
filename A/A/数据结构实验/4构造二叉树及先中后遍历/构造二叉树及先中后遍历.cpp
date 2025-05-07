#include<stdio.h>
#include<stdlib.h>//mslloc、exit

typedef int TElemType;

typedef struct BitNode {
	TElemType data;
	struct BitNode *lchild, *rchild;
}BitNode, *BiTree;          //BiTree相当于BitNode*

void CreateBiTree(BiTree &T)
{
	TElemType x;
	scanf("%d", &x);
	if (x < 0)
		T = NULL;
	else
	{
		if (!(T = (BiTree)malloc(sizeof(BitNode))))//
			exit;//exit(1)返回的值                 //T = new BitNode;不是BiTree
		T->data = x;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PrintElement(TElemType e)
{
	printf("%d ", e);
}

void PreOrderTraverse(BiTree T, void(*Visit)(TElemType e))
{
	if (T)
	{
		Visit(T->data);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
}

void InOrderTraverse(BiTree T, void(*Visit)(TElemType e))
{
	if (T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T->data);
		InOrderTraverse(T->rchild, Visit);
	}
}

void PostOrderTraverse(BiTree T, void(*Visit)(TElemType e))
{
	if (T)
	{
		PostOrderTraverse(T->lchild, Visit);
		PostOrderTraverse(T->rchild, Visit);
		Visit(T->data);
	}
}

int main()
{
	BiTree t;
	printf("构造二叉树：");
	CreateBiTree(t);

	printf("先中后遍历二叉树分别为：\n");
	PreOrderTraverse(t, PrintElement);
	printf("\n");

	InOrderTraverse(t, PrintElement);
	printf("\n");

	PostOrderTraverse(t, PrintElement);
	printf("\n");
}