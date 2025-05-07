#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LNode
{
	int x, t=0;
	LNode *next;
	LNode *l;
}LNode,*LinkList;
int main()
{
	int i, j, N, A[100][100], t[100], m, n;
	char a[10], b[10];
	scanf_s("%d", &N);
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n - 1;i >= 0;i--)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->x = i;
		p->next = L->next;
		L->next = p;
	}
	while (scanf_s("%s", a, 10) != EOF)
	{
		if (a == "quit")
			break;
		else
		{
			scanf_s("%d", &m);
			scanf_s("%s", b, 10);
			scanf_s("%d", &n);
			LinkList p = L;//m
			LinkList q = L;//n
			for (i = 0;i < m - 1;i++)
				p = p->next;
			for (i = 0;i < n;i++)
				q = q->next;
			LinkList r = p->next;
			p->next = r->next;
			if (strcmp(a, "move") == 0)
			r->l=
			else
			{
				q->l = r;
			}
			if (strcmp(b, "onto") == 0)
			{
				r->next = q->l;
				q->l = r;
			}
			else
			{
				LinkList k = q->l;
				for (i = 0;k->next!=NULL;i++)
					k = k->next;
				k->next=r;
			}
		}
	}
	LinkList p = L;
	while (p)
	{
		i = 0;
		printf("%d:", i++);
		LinkList q = p->l;
		while (q)
		{
			printf(" %d", q->next->x);
			q = q->next;
		}
		p = p->next;
	}
	return 0;
}