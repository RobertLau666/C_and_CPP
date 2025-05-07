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

int StackLength(SqStack S)//返回元素个数
{
	return S.length;
}
Status InitStack(SqStack &S)//构造空栈
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	S.length=0;
	return OK;
}

Status GetTop(SqStack S, SElemType &e)//返回栈顶元素
{
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e)//插入
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

Status Pop(SqStack &S, SElemType &e)//删除栈顶元素
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	S.length--;
	return OK;
}

Status ListTraverse(SqStack S, void visit(SElemType*))//输出
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

	InitStack(A);//构造栈A

	printf("输入A:");//插入
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		Push(A, m);
		a = getchar();
	} while (a == ' ');
	ListTraverse(A, print);

	Pop(A, e);//删除栈顶元素
	printf("删除了栈顶元素%d\n", e);
	ListTraverse(A, print);

	GetTop(A, e);//返回栈顶元素
	printf("此时栈顶元素为%d\n", e);

	printf("输入一个要插入的栈顶元素：");
	scanf_s("%d", &e);
	Push(A, e);
	ListTraverse(A, print);

	GetTop(A, e);//返回栈顶元素
	printf("此时栈顶元素为%d\n", e);
	return 0;
}