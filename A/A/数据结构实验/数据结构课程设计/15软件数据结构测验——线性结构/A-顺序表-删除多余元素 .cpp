#include<stdio.h>
#include<stdlib.h>
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;
int main()
{
	int i, j, k, N, M;
	LinkList p, q, r, L;
	scanf_s("%d", &M);
	for (k = 0; k < M; k++)
	{
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		r = L;
		scanf_s("%d", &N);
		for (i = 0; i < N; i++)
		{
			p = (LinkList)malloc(sizeof(LNode));
			scanf_s("%d", &p->data);             //&
			p->next = NULL;
			r->next = p;
			r = r->next;
		}

		p = L->next;                  //ɾ���������ֵ
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
				}
				else                   //else
					q = q->next;
			}
			p = p->next;
			if (!p)                //���pΪNULL,��p->next����������ڴ��ж�
				break;
		}

		p = L->next;
		while (p)
		{
			if (p->next)
				printf("%d ", p->data);
			else
				printf("%d\n", p->data);
			p = p->next;
		}
	}
	return 0;
}

//#include<iostream>
//#include<malloc.h>
//#define LIST_INIT_SIZE  10005
//#define LISTINCREMENT  10
//using namespace std;
//typedef struct {
//	int *elem;
//	int length;
//	int listsize;
//}SqList;
//void InitList_Sq(SqList &L)
//{
//	L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
//	L.length = 0;
//	L.listsize = LIST_INIT_SIZE;
//}
//void CreatList(SqList &L, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cin >> L.elem[i];
//	}
//	L.length = n;
//}
//void PrintList(SqList L)
//{
//	cout << L.elem[0];
//	for (int i = 1; i < L.length; i++)
//	{
//		cout << " " << L.elem[i];
//	}
//	cout << endl;
//}
//void DeleteList(SqList &L)
//{
//	int l = 1;
//	for (int i = 1; i < L.length; i++)
//	{
//		int flag = 1;
//		for (int j = 0; j < l; j++)
//		{
//			if (L.elem[i] == L.elem[j])
//			{
//				flag = 0; break;
//			}
//		}
//		if (flag == 1)
//		{
//			L.elem[l] = L.elem[i];
//			l++;
//		}
//	}
//	L.length = l;
//}
//int main()
//{
//	int m;
//	cin >> m;
//	while (m--)
//	{
//		int n;
//		SqList L;
//		InitList_Sq(L);
//		cin >> n;
//		CreatList(L, n);
//		DeleteList(L);
//		PrintList(L);
//	}
//	return 0;
//}

//#include <stdio.h>  
//#include <stdlib.h>  
//#define maxsize 10000  
//
//typedef int Element_int;
//typedef struct
//{
//	Element_int *elem;//����int����Ԫ��elem��elemû�п��ٿռ䣬ǰ���*��  
//	int length;//����  
//	int listsize;
//}Sq;
//int Initialize_List(Sq *L);//��ʼ����  
//void Creat_List(Sq *L, int len);//����  
//int Del(Sq *L, int k);//ɾ��������  
//void Re_List(Sq *L);//����ɾ��������  
//void Print_List(Sq *L);//�������֮��ı�  
//int main()
//{
//	Sq L;
//	int n, m;//�������ݵ�����Ŀ�Լ�ÿ�����ݵ���Ŀ��  
//	while (~scanf("%d", &n))
//	{
//		while (n--)
//		{
//			scanf("%d", &m);
//			Initialize_List(&L);//��ʼ��������  
//			Creat_List(&L, m);//���������  
//			Re_List(&L);//����ɾ��������  
//			Print_List(&L);//���������  
//		}
//	}
//}
//int Initialize_List(Sq * L)
//{
//	L->elem = (Element_int *)malloc(maxsize * sizeof(Element_int));//����ռ䣻  
//	if (!L->elem) return -1;//����д��exit(-1);  
//	L->length = 0;
//	L->listsize = maxsize;
//	return 0;
//}
//void Creat_List(Sq *L, int len)
//{
//	L->length = len;
//	for (int i = 0; i<len; i++)
//		scanf("%d", &L->elem[i]);
//}
//int Del(Sq *L, int k)
//{
//	Element_int *p, *q;
//	if (k<1 || k>L->length)
//		return 0;
//	q = L->elem + L->length;
//	for (p = &(L->elem[k]); p<q; p++)//���Ʋ�����  
//		*p = *(p + 1);
//	L->length--;//����һ��  
//	return 1;
//}
//void Re_List(Sq *L)
//{
//	Element_int *p, *q;//������Ԫ��������ͬ��ָ�룻  
//
//	for (p = L->elem; p<L->elem + L->length; p++)
//		for (q = p + 1; q<L->elem + L->length; q++)
//			if (*p == *q)
//			{
//				Del(L, (q - L->elem));
//				q--;//ִ����if������q���ƣ������Ʋ�����qָ��λ�õ������Ѹ��£�  
//					//���q��Ҫִ��--�������Ա��жϵ�ǰλ�õ������Ƿ���Ҫɾȥ��  
//			}
//}
//void Print_List(Sq *L)
//{
//	for (int i = 0; i<L->length; i++)
//		printf(i == L->length - 1 ? "%d\n" : "%d ", L->elem[i]);
//}