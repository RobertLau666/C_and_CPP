//Graph.cpp 
#include "Graph.h" 
#include <iostream> 
#include <stdlib.h> 
#include <fstream> 
#include <string> 
using namespace std; 
Graph::Graph() 
{ 
numofedges = 0; }
Graph ::~Graph() 
{
}
void Graph::ReadVertex()
{
	int i = 0, v; char ch[20];
	fstream infile(" ����ʽ��ֵ .txt", ios::in);
	while (infile >> ch && infile >> v)
	{
#ifdef MY_DEBUG printf("%s\t%d\n", ch, v); 
#endif V[i].value = v; V[i].cost = 0; strcpy(V[i].cityname, ch); i++; 
	}
}
void Graph::ReadEdge()
{
	int valu, i;
	fstream infile(" ��ͼ���ݱ� .txt", ios::in);
	i = 0;
	while (infile >> valu)
	{
		edge[i / 20][i % 20] = valu;
#ifdef MY_DEBUG if (i % 20 == 0)cout << endl; 
		cout << edge[i / 20][i % 20] << "\t";
#endif i++;
	}
}
// ȡ��� V���ڵ�ĵ�һ���ڽӵ�
int Graph::GetFirstVertex(int v)
{
	if (v<0 || v >= 20) { return -1; } for (int col = 0; col<20; col++) if (edge[v][col]>0 && edge[v][col]<1000) return col; return -1;
}
// �ҵ��� V1���ڵ�� V2֮�����һ���ڽӽڵ�
int Graph::GetNextVertex(int v1, int v2) {
	if (v1<0 || v1 >= 20 || v2<0 || v2 >= 20) { return -1; } for (int col = v2 + 1; col<20; col++) if (edge[v1][col]>0 && edge[v1][col]<1000) return col; return -1;
}
int Graph::GetVerValue(int index) // ��ȡ V[index] ��ver ��values ֵ
{
	return V[index].value;
}
int Graph::GetVerCost(int index) // ��ȡ V[index] ��ver ��cost ֵ
{
	return V[index].cost;
}
int Graph::GetEdge(int row, int col) // ��ȡ edge[row][col] ��ֵ
{
	return edge[row][col];
} void Graph::SetVerCost(int index, int cost) { V[index].cost = cost; }
