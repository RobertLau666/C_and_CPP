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

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList(SqList &L)//构造空表
{
	L.elem = (ElemType*)malloc(LIST_INIT__SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT__SIZE;
	return OK;
}

Status ClearList(SqList &L)//重置
{
	L.length = 0;
	return OK;
}

Status DestroyList(SqList &L)//销毁
{
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType &e)
{
	if (i < 1 || i >L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

Status ListInsert(SqList &L, int i, ElemType e)//插入
{
	ElemType *p, *q;
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length >= L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(ERROR);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L, int i, ElemType&e)//删除
{
	ElemType *p, *q;
	if ((i < 1) || (i > L.length))
		return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)*(p - 1) = *p;
	--L.length;
	return OK;
}

//2.7
void MergeList_L(SqList La,SqList Lb,SqList&Lc)
{
	ElemType* pa = La.elem, *pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);
	ElemType* pa_last = La.elem + La.length - 1;
	ElemType* pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last&&pb <= pb_last)
	{
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
}

////2.2
//void MergeList_L(SqList La, SqList Lb, SqList &Lc)//并
//{
//	ElemType ai, bj;
//	InitList(Lc);//构造一个新的线性表
//	int i = 1, j = 1,k=0;
//	int La_len = ListLength(La);
//	int Lb_len = ListLength(Lb);
//	while ((i <= La_len) && (j <= Lb_len))//La和Lb均非空
//	{
//		GetElem(La, i, ai);
//		GetElem(Lb, j, bj);
//		if (ai <= bj)
//		{
//			ListInsert(Lc, ++k, ai);
//			++i;
//		}
//		else
//		{
//			ListInsert(Lc, ++k, bj);
//			++j;
//		}
//	}
//	while (i <= La_len)
//	{
//		GetElem(La, i++, ai);
//		ListInsert(Lc, ++k, ai);
//	}
//	while (j <= Lb_len)
//	{
//		GetElem(Lb, j++, bj);
//		ListInsert(Lc, ++k, bj);
//	}
//	printf("A和B的合并为：");
//}

Status ListTraverse(SqList L, void visit(ElemType*))//输出
{
	ElemType *p;
	int i;
	p = L.elem;
	for (i = 1; i <= L.length; i++)
		visit(p++);
	printf("\n");
	return OK;
}

void print(ElemType *c)
{
	printf("%d ", *c);
}

int main()
{
	char a;
	int i, m;
	SqList A, B, C;
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

	MergeList_L(A, B, C);//并
	ListTraverse(C, print);
	ClearList(C);

	DestroyList(A);
	DestroyList(B);
	DestroyList(C);
}