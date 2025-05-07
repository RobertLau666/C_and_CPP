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
typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q)//构造
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q)//销毁
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e)//插入
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)//删除
{
	if (Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

void ListTraverse(LinkQueue Q, void visit(QElemType))//输出
{
	QueuePtr p = Q.front->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
}

void print(QElemType c)
{
	printf("%d ", c);
}

int main()
{
	char a;
	int i, m, e;
	LinkQueue A;

	InitQueue(A);//构造队列A

	printf("输入A:");//插入
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		EnQueue(A,m);
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

	DestroyQueue(A);
	return 0;
}