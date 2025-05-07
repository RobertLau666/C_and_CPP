#include<stdio.h>
#include<stdlib.h>     
typedef struct LNode    
{
    int data;    
    struct LNode *next;    
}LNode,*LinkList;
int main()
{
	int n, i, m = 0;
	LinkList L, p, q, r;

	L = (LinkList)malloc(sizeof(LNode));//µ¹Ðð
	L->next = NULL;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf_s("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}

	printf("%d\n", n);
	p = L->next;
	while (p)
	{
		if (p->next != NULL)
			printf("%d ", p->data);
		else 
			printf("%d", p->data);
		p = p->next;
	}

	p = L->next;
	while (p->next)
	{
		q = p;
		while (q->next)
		{
			if (q->next->data == p->data)
			{
				r = q->next;
				q->next = r->next;
				free(r);
				m++;
			}
			else 
				q = q->next;
		}    
		p = p->next;
		if (!p)
			break;
	}

	printf("\n%d\n", n - m);
	p = L->next;
	while (p)
	{
		if (p->next != NULL)
			printf("%d ", p->data);
		else 
			printf("%d\n", p->data);
		p = p->next;
	}
	return 0;
}
///////////////////////diy
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct LNode
//{
//	int data;
//	struct LNode *next;
//}LNode, *LinkList;
//int main()
//{
//	int i, n, m = 0;
//	LinkList L, p, q, r;
//	L = (LinkList)malloc(sizeof(LNode));
//	L->next = NULL;
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(LNode));
//		scanf_s("%d", &p->data);
//		p->next = L->next;
//		L->next = p;
//	}
//	printf("%d\n", n);
//	p = L->next;
//	while (p)
//	{
//		if (p->next)
//			printf("%d ", p->data);
//		else
//			printf("%d\n", p->data);
//		p = p->next;
//	}
//	p = L->next;
//	while (p->next)
//	{
//		q = p;
//		while (q->next)
//		{
//			if (q->next->data == p->data)
//			{
//				r = q->next;
//				q->next = r->next;
//				free(r);
//				m++;
//			}
//			else
//				q = q->next;
//		}
//		p = p->next;
//	}
//	printf("%d\n", n - m);
//	p = L->next;
//	while (p)
//	{
//		if (p->next)
//			printf("%d ", p->data);
//		else
//			printf("%d\n", p->data);
//		p = p->next;
//	}
//	return 0;
//}