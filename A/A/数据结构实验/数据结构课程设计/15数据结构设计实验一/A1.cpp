#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

struct  LNode {
	int data;
	LNode *next;
};

typedef LNode *LinkList;
int InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (!L)
		exit(OVERFLOW);
	L->next = NULL;
	return OK;
}

void CreateList(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i =n; i>0; i--)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		p->next = L->next;
		L->next = p;
	}
}

int ListDelete(LinkList &L, int i, int&e)
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
			i=1;
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
	int i,k,e,N,n;
	LinkList A;
	
	scanf_s("%d",&N);
	for (i = 0; i < N; i++)
	{
		scanf_s("%d",&n);
		CreateList(A, n);
		while (1)
		{
			for(k=2;k<= ListLength(A);k++)
				ListDelete(A, k, e);
			if (ListLength(A) <= 3)
			{
				ListTraverse(A, print);
				break;
			}

			for (k = 3; k<= ListLength(A); k=k+2)
				ListDelete(A, k, e);
			if (ListLength(A) <= 3)
			{
				ListTraverse(A, print);
				break;
			}
		}
	}
}