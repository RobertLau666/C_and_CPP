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

#define MAXQSIZE 100

typedef int Status;
typedef int QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q)//�������
{
	Q.base = (QElemType *)malloc(MAXQSIZE *sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q)//����Ԫ�ظ����������г���
{
	return (Q.rear-Q.front+MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e)//�����β
{
	if ((Q.rear+1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)//ɾ����ͷ
{
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

Status ListTraverse(SqQueue Q, void visit(QElemType))//���
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

	InitQueue(A);//�������A

	printf("����A:");//����
	i = 0;
	do {
		scanf_s("%d", &m);
		i++;
		EnQueue(A, m);
		a = getchar();
	} while (a == ' ');
	ListTraverse(A, print);

	DeQueue(A, e);//ɾ����ͷԪ��
	printf("ɾ���˶�ͷԪ��%d\n", e);
	ListTraverse(A, print);

	printf("����һ��Ҫ����Ķ�βԪ�أ�");
	scanf_s("%d", &e);
	EnQueue(A, e);
	ListTraverse(A, print);
	return 0;
}