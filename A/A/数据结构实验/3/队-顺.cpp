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

#define MAXQSIZE 100

typedef int Status;
typedef int QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q)//构造队列
{
	Q.base = (QElemType *)malloc(MAXQSIZE *sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)//返回元素个数，即队列长度
{
	return (Q.rear-Q.front+MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e)//插入队尾
{
	if ((Q.rear+1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)//删除对头
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

Status ListTraverse(SqQueue Q, void visit(QElemType))//输出
{
	QElemType *p;
	int i;
	p = Q.base;
	for (i = Q.front; i <Q.front + QueueLength(Q); i++)
	{
		if (i == MAXQSIZE)
			i -= MAXQSIZE;
		visit(p[i]);
	}
	printf("\n");
	return OK;
}

void print(QElemType c)
{
	printf("%d ", c);
}

int main()
{
	char a;
	int i, m, e;
	SqQueue A;

	InitQueue(A);//构造队列A

	printf("输入A:");//插入
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		EnQueue(A, m);
		a = getchar();
	} while (a == ' ');
	ListTraverse(A, print);

	DeQueue(A, e);//删除对头元素
	printf("删除了对头元素%d\n", e);
	ListTraverse(A, print);

	printf("输入一个要插入的队尾元素：");
	scanf_s("%d", &e);
	EnQueue(A, e);
	ListTraverse(A, print);
	return 0;
}