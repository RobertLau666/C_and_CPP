#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define INFEASZAIBLE -1//����ʵ�е�
#define OVERFLOW -2//���

typedef int Status;
typedef int InfoType;
typedef int VertexType;

#define MAX_VERTEX_NUM 20

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;

typedef struct VNode {
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

int LocateVex(ALGraph &G, int v)
{
	int i, j = 0;
	for (i = 0; i<G.vexnum; i++)
		if (G.vertices[i].data==v)
		{
			j = i;
			break;
		}
	return j;
}

Status CreateDG(ALGraph &G)
{
	int i,j,k,v1,v2;
	ArcNode* p;
	printf("��������ͼ�Ķ����뻡�ĸ�����");
	scanf_s("%d %d",&G.vexnum,&G.arcnum);
	printf("���붥�㣺");
	for (i = 0; i < G.vexnum; ++i)
	{
		scanf_s("%d",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		printf("���뻡�������յ㣺");
		scanf_s("%d %d",&v1,&v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc= p;
	}
	return OK;
}

void IN(ALGraph G)
{
	int i, j, t[100] = {0};
	ArcNode *p;
	printf("��ȷֱ��ǣ�");
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			t[p->adjvex]++;
			p = p->nextarc;
		}
	}
	for (i = 0; i < G.vexnum; i++)
		printf("%d", t[i]);
	printf("\n");
}

void OUT(ALGraph G)
{
	int t;
	ArcNode *p;
	printf("���ȷֱ��ǣ�");
	for (int i = 0; i < G.vexnum; i++)
	{
		t = 0;
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			t++;
			p = p->nextarc;
		}
		printf("%d", t);
	}
	printf("\n");
}

int main()
{
	ALGraph G;
	CreateDG(G);
	OUT(G);
	IN(G);
}