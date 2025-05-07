#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;
int main()
{
	int i, j, N,a;
	LinkList p, q, r, L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	scanf_s("%d",&N);
	for (i = 0; i < N; i++)
	{
		p= (LinkList)malloc(sizeof(LNode));
		scanf_s("%d",&p->data);
		p->next = NULL;
		r->next = p;
		r = r->next;
	}

	scanf_s("%d",&a);

	printf("%d\n",N);
	p = L->next;
	while (p)
	{
		if (p->next)
			printf("%d ",p->data);
		else
			printf("%d\n", p->data);
		p = p->next;
	}

	p = L;                           //删除特定数值
	while (p->next)
	{
		if (p->next->data == a)
		{
			r = p->next;
			p->next = r->next;
			free(r);
			N--;
		}
		p = p->next;
		if (!p)         //如果p为NULL,则p->next会出错，所以在此判断
			break;
	}

	printf("%d\n", N);
	p = L->next;
	while (p)
	{
		if (p->next)
			printf("%d ", p->data);
		else
			printf("%d\n", p->data);
		p = p->next;
	}
	return 0;
}

//#include<iostream>
//#include<malloc.h>
//typedef struct LNode {
//	int data;
//	struct LNode *next;
//}LNode, *LinkList;
//using namespace std;
//void CreatList(LinkList &L, int n)
//{
//	LinkList q, p;
//	L = (LinkList)malloc(sizeof(LNode));
//	L->next = NULL;
//	q = L;
//	while (n--)
//	{
//		p = (LinkList)malloc(sizeof(LNode));
//		cin >> p->data;
//		q->next = p;
//		p->next = NULL;
//		q = p;
//	}
//}
//void PrintList(LinkList L)
//{
//	LinkList q;
//	q = L->next;
//	if (q != NULL)
//	{
//		cout << q->data;
//		q = q->next;
//	}
//	while (q != NULL)
//	{
//		cout << " " << q->data;
//		q = q->next;
//	}
//	cout << endl;
//}
//int Listlength(LinkList L)
//{
//	int length = 0;
//	LinkList p;
//	p = L->next;
//	while (p != NULL)
//	{
//		length++;
//		p = p->next;
//	}
//	return length;
//}
//void ListDelete_L(LinkList &L, int i)
//{
//	LinkList p, q;
//	int j = 0;
//	p = L;
//	while (p->next&&j < i - 1)
//	{
//		p = p->next;
//		++j;
//	}
//	q = p->next;
//	p->next = q->next;
//	free(q);
//}
//void ListDelete(LinkList &L, int m)
//{
//	LinkList p, q, t;
//	int i;
//	p = L->next;
//	while (p != NULL)
//	{
//		i = 0;
//		q = L;
//		while (q != p)
//		{
//			i++;
//			q = q->next;
//		}
//		t = p->next;
//		if (m == p->data)
//		{
//			ListDelete_L(L, i);
//		}
//		p = t;
//	}
//}
//int main()
//{
//	int n, m;
//	LinkList L;
//	cin >> n;
//	CreatList(L, n);
//	cin >> m;
//	cout << n << endl;
//	PrintList(L);
//	ListDelete(L, m);
//	cout << Listlength(L) << endl;
//	PrintList(L);
//	return 0;
//}

//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//#include<cmath>
//#include<malloc.h>
//#include<algorithm>
//#include<queue>
//#include<stack>
//using namespace std;
//typedef long long ll;
//typedef struct node {
//	struct node *next;
//	int data;
//}ln, *ls;
//int n, m;
//ls build(int n) {
//	ls p = NULL, q = NULL;
//	ls l = (ls)malloc(sizeof(ln));
//	l->next = NULL;
//	for (int i = 0; i<n; ++i) {
//		p = (ls)malloc(sizeof(ln));
//		scanf("%d", &(p->data));
//		p->next = NULL;
//		if (l->next) {
//			q->next = p;
//		}
//		else {
//			l->next = p;
//		}
//		q = p;
//	}
//	return l;
//}
//ls del(ls l, int m) {
//	ls p = l->next;
//	ls q = l;
//	while (p) {
//		if (p->data == m) {
//			q->next = p->next;
//			free(p);
//			p = q->next;
//			--n;
//		}
//		else {
//			p = p->next;
//			q = q->next;
//		}
//	}
//	return l;
//}
//void print(ls l) {
//	l = l->next;
//	while (l) {
//		if (l->next == NULL) {
//			printf("%d\n", l->data);
//		}
//		else {
//			printf("%d ", l->data);
//		}
//		l = l->next;
//	}
//}
//int main() {
//	scanf("%d", &n);
//	ls l = build(n);
//	printf("%d\n", n);
//	print(l);
//	scanf("%d", &m);
//	l = del(l, m);
//	printf("%d\n", n);
//	print(l);
//}
//
