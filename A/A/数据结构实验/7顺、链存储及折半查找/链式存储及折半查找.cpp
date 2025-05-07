#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2//���

#define EQ(a,b) (a==b)
#define LT(a,b) (a<b)
#define LQ(a,b) (a<=b)

typedef int Status;
typedef int KeyType;

typedef struct SNode{//�������
	KeyType key;
	struct SNode *next;
}*LinkList;                //Link=SNode*,��Ϊָ�����ָ������

Status Create(LinkList &ST, int n)
{
	int i;
	LinkList r,p;
	ST = (LinkList)malloc(sizeof(SNode));
	ST->next = NULL;
	r = ST;
	printf("��������Ԫ�أ�");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(SNode));
		scanf_s("%d",&p->key);
		p->next = NULL;
		r->next = p;
		r = r->next;
	}
	return OK;
}

int ListLength(LinkList ST)
{
	int i = 0;
	LinkList p = ST->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetElem(LinkList L, int i, KeyType &e)
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
	e = p->key;
	return OK;
}

int Search_Bin(LinkList ST, KeyType key)
{
	int low = 1, high = ListLength(ST), mid;
	KeyType e;
	while (low <= high)
	{
		mid = (low + high) / 2;
		GetElem(ST, mid, e);
		if (EQ(key, e))
			return mid;
		else
			if (LT(key, e))
				high = mid - 1;
			else
				low = mid + 1;
	}
	return 0;
}

int main()
{
	LinkList T;
	int n, m, i = 2;
	printf("��ʽ�洢���۰����\n����������Ԫ�ظ�����");
	scanf_s("%d", &n);
	Create(T, n);
	while (i)
	{
		printf("�������Ԫ�أ�");
		scanf_s("%d", &m);
		printf("λ���ǣ�%d\n", Search_Bin(T, m));
		i--;
	}
}