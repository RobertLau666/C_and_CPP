#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define INFEASZAIBLE -1//不可实行的
#define OVERFLOW -2//溢出

typedef int Status;
typedef char TElemType;
typedef enum PointerTag{ Link, Thread };//默认分别为0和1

typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;     

Status PrintElement(TElemType e)
{
	printf("%c", e);
	return OK;
}

BiThrTree pre;

void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}

Status InOrderThreading(BiThrTree&Thrt,BiThrTree T)
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
		exit(OVERFLOW);
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;
	if (!T)
		Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T);
		pre->rchild = Thrt;
		pre->RTag = Thread;
		Thrt->rchild = pre;
	}
	return OK;
}

Status CreateBiTree(BiThrTree &T)
{
	char x;
	scanf_s("%c",&x);
	if (x ==' ')
		T = NULL;
	else
	{
		if (!(T = (BiThrTree)malloc(sizeof(BiThrNode))))
			exit(OVERFLOW);
		T->LTag = T->RTag = Link;
		T->data = x;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
	BiThrTree p;
	p = T->lchild;
	while (p != T)
	{
		while (p->LTag == Link)
			p = p->lchild;
		if (!Visit(p->data))
			return ERROR;
		while (p->RTag == Thread&&p->rchild != T)
		{
			p = p->rchild;
			Visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree t, Th;
	printf("构造二叉树\n");
	CreateBiTree(t);

	printf("线索化\n");
	InOrderThreading(Th, t);
	InOrderTraverse_Thr(Th, PrintElement);
}
