#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASZAIBLE -1
#define OVERFLOW -2
#define LIST_INIT__SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void CreateList_L(LinkList &L, int n)
{
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
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

int ListDelete(LinkList &L, int i, ElemType&e)
{
	LinkList p = L, q;
	int j = 0;
	while (p->next&&j < i - 1)
	{
		p = p->next;
		++j;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 0;
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

void ListTraverse(LinkList L, void visit(int))
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		if (i == 0)
		{
			printf("%d", p->data);
			i = 1;
		}
		else
			visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void print(int c)
{
	printf(" %d", c);
}

int main()
{
	int i, j, n, a, b, e;
	LinkList L;
	scanf_s("%d", &n);
	CreateList_L(L, n);
	printf("%d\n",n);
	ListTraverse(L, print);
	for (i = 1; i <= ListLength(L); i++)
	{
		GetElem(L, i, a);
		for (j = i + 1; j <= ListLength(L); j++)
		{
			GetElem(L, j, b);
			if (a == b)
			{
				ListDelete(L, j, e);
			}
		}
	}
	printf("%d\n", ListLength(L));
	ListTraverse(L, print);
}