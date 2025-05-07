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

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
	int length;
}SqStack;

int StackLength(SqStack S)//����Ԫ�ظ���
{
	return S.length;
}
Status InitStack(SqStack &S)//�����ջ
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	S.length=0;
	return OK;
}

Status GetTop(SqStack S, SElemType &e)//����ջ��Ԫ��
{
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e)//����
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
			exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	S.length++;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)//ɾ��ջ��Ԫ��
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	S.length--;
	return OK;
}

Status ListTraverse(SqStack S, void visit(SElemType*))//���
{
	SElemType *p;
	int i;
	p = S.top-1;
	for (i = 1; p>=S.base; i++)
		visit(p--);
	printf("\n");
	return OK;
}

void print(SElemType *c)
{
	printf("%d ", *c);
}

int main()
{
	char a;
	int i, m, e;
	SqStack A;

	InitStack(A);//����ջA

	printf("����A:");//����
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		Push(A, m);
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
}