#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASZAIBLE -1//����ʵ�е�
#define OVERFLOW -2//���
#define LIST_INIT__SIZE 100
#define LISTINCREMENT 10

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int SElemType;

struct  SNode {
	SElemType data;
	SNode *next;
};

typedef SNode *StackPtr;

Status InitStack(StackPtr &S)//����ձ�
{
	S = (StackPtr)malloc(sizeof(SNode));
	if (!S)
		exit(OVERFLOW);
	S->next = NULL;
	return OK;
}

Status DestroyStack(StackPtr &S)//����
{
	StackPtr q;
	while (S)
	{
		q = S->next;
		free(S);
		S = q;
	}
	return OK;
}

Status GetTop(StackPtr S, SElemType &e)//����ջ��Ԫ��
{
	if (S==NULL)
		return ERROR;
	e = S->data;
	return OK;
}

int StackLength(StackPtr S)//ջԪ�ظ���
{
	int i = 0;
	StackPtr p = S->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status Push(StackPtr &S, SElemType e)//����ջ��
{
	StackPtr p = (StackPtr)malloc(sizeof(SNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}

Status Pop(StackPtr &S, SElemType&e)//ɾ��ջ��
{
	StackPtr p;
	if (S->next==NULL)//ǧ�������һ����=��
		return ERROR;
	e = S->data;
	p = S;
	S = p->next;
	free(p);
	return OK;
}

void ListTraverse(StackPtr S, void visit(SElemType))//���
{ 
	StackPtr p = S;
	while (p->next)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void print(SElemType c)
{
	printf("%d ", c);
}

int main()
{
	int i,e, m;
	char a;
	StackPtr A;
	InitStack(A);

	printf("Enter A:");
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		Push(A,m);
		a = getchar();
	} while (a == ' ');
	ListTraverse(A, print);

	Pop(A, e);//ɾ��ջ��Ԫ��
	printf("ɾ����ջ��Ԫ��%d\n", e);
	ListTraverse(A, print);

	GetTop(A, e);//����ջ��Ԫ��
	printf("��ʱջ��Ԫ��Ϊ%d\n", e);

	printf("����һ��Ҫ�����ջ��Ԫ�أ�");
	scanf_s("%d", &e);
	Push(A, e);
	ListTraverse(A, print);

	GetTop(A, e);//����ջ��Ԫ��
	printf("��ʱջ��Ԫ��Ϊ%d\n", e);
	return 0;

	DestroyStack(A);
}