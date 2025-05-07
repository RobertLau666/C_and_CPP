#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASZAIBLE -1//不可实行的
#define OVERFLOW -2//溢出
#define LIST_INIT__SIZE 100
#define LISTINCREMENT 10

typedef int Status;
typedef int ElemType; 

struct  LNode{
	ElemType data;
	LNode *next;
};

typedef LNode *LinkList;

Status InitList(LinkList &L)//构造空表
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

Status DestroyList(LinkList &L)//销毁
{
	LinkList q;
	while (L)
	{
		q = L->next;
		free(L);
		L = q;
	}
	return OK;
}

Status ClearList(LinkList &L)//重置
{
	LinkList p = L->next;
	L->next = NULL;
	DestroyList(p);
	return OK;
}

Status ListEmpty(LinkList L)//判断是否为空表
{
	if (L->next)//非NULL
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
	LinkList p = L->next;
	int j = 1;
	while (p&&j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ 
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem(LinkList L, ElemType cure_e,ElemType &pre_e)
{
	LinkList q, p = L->next;
	while (p->next)
	{
		q = p->next;
		if (q->data ==cure_e)
		{
			pre_e = p->data;
			return OK;
		}
		p = q;
	}
	return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
	LinkList p = L->next;
	while (p->next)
	{
		if (p->data == cur_e)
		{
			next_e = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status ListInsert(LinkList &L, int i, ElemType e)//插入
{
	LinkList p = L;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1)
		return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L, int i, ElemType&e)//删除
{
	LinkList p = L, q;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void ListTraverse(LinkList L, void visit(ElemType))//输出
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void print(ElemType c)
{
	printf("%d ", c);
}

void CreateList(LinkList &L, int n)//构造一个有n位的表
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; --i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void JIAO_List(LinkList La, LinkList Lb, LinkList &Lc)//交
{
	int i, j, k = 0;
	ElemType ai = 0, bj = 0;
	LinkList pa, pb;
	InitList(Lc);//构造一个新的线性表
	pa = La->next;
	pb = Lb->next;
	for (i = 1; pa != NULL; i++, pa = pa->next)
	{
		GetElem(La, i, ai);
		for (j = 1; pb != NULL; j++, pb = pb->next)
		{
			GetElem(Lb, j, bj);
			if (ai == bj)
			{
				k++;
				ListInsert(Lc, k, ai);
			}
		}
		pb = Lb->next;
	}
	printf("A∩B:");
}

void BING_List(LinkList La, LinkList Lb, LinkList &Lc)//并
{
	int e, i, j, k = 0;
	ElemType ai, bj;
	LinkList pa, pb;
	InitList(Lc);//构造一个新的线性表
	pa = La->next;
	pb = Lb->next;
	while (pa&&pb)
	{
		if (pa->data <= pb->data)
		{
			ListInsert(Lc, ++k, pa->data);
			pa = pa->next;
		}
		else
		{
			ListInsert(Lc, ++k, pb->data);
			pb = pb->next;
		}
	}
	if (pa)
	{
		for (i = 0; pa != NULL; i++, pa = pa->next)
			ListInsert(Lc, ++k, pa->data);
	}
	else
		for (i = 0; pb != NULL; i++, pb = pb->next)
			ListInsert(Lc, ++k, pb->data);
	for (i = 1; i <= ListLength(Lc); i++)
	{
		GetElem(Lc, i, ai);
		for (j = 1; j < i; j++)
		{
			GetElem(Lc, j, bj);
			if (ai == bj)
			{
				ListDelete(Lc, j, e);
				i--;
				break;
			}
		}
	}
	printf("A∪B:");
}

void CHA_List(LinkList La, LinkList Lb, LinkList &Lc)//差
{
	int i, j, k = 0;
	ElemType ai = 0, bj = 0;
	LinkList pa, pb;
	InitList(Lc);//构造一个新的线性表
	pa = La->next;
	pb = Lb->next;
	for (i = 1; pa != NULL; i++, pa = pa->next)
	{
		GetElem(La, i, ai);
		for (j = 1; pb != NULL; j++, pb = pb->next)
		{
			GetElem(Lb, j, bj);
			if (ai == bj)
				break;
		}
		if (j > ListLength(Lb))
		{
			k++;
			ListInsert(Lc, k, ai);
		}
		pb = Lb->next;
	}
	printf("A-B:");
}

int main()
{
	int i, m;
	char a;
	LinkList A, B, C;
	InitList(A);
	InitList(B);

	printf("Enter A:");
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		ListInsert(A, i, m);
		a = getchar();
	} while (a == ' ');
	printf("A:");
	ListTraverse(A, print);

	printf("Enter B:");
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		ListInsert(B, i, m);
		a = getchar();
	} while (a == ' ');
	printf("B:");
	ListTraverse(B, print);

	JIAO_List(A, B, C);//交
	ListTraverse(C, print);
	ClearList(C);

	BING_List(A, B, C);//并
	ListTraverse(C, print);
	ClearList(C);

	CHA_List(A, B, C);//差
	ListTraverse(C, print);

	DestroyList(A);
	DestroyList(B);
	DestroyList(C);
}