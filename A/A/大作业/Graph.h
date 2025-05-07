//Graph.h 
#pragma once
using namespace std; 
#define MaxV 20  /*#ifndef MY_DEBUG #define MY_DEBUG #endif*/ 
typedef struct {
char cityname[20]; // ������
int  value; // Ȩֵ
int  cost; //A* �㷨�дӵ�ǰ�ڵ��ƶ���Ŀ��ڵ��Ԥ������
} Ver;
class Graph {
public: Graph(); ~Graph(); 
		Ver V[MaxV]; 
		int edge[MaxV][MaxV];
		int numofedges;    // ע���������������λ��
						   // ��ȡ��ͼ�ڵ���Ϣ
		void ReadVertex();
		// ��ȡ��ͼ�߹�ϵ��Ϣ
		void ReadEdge();
		// ȡ��� V���ڵ�ĵ�һ���ڽӵ�
		int GetFirstVertex(int v);
		// �ҵ��� V1���ڵ�� V2֮�����һ���ڽӽڵ�
		int GetNextVertex(int v1, int v2);
		int GetVerValue(int index); // ��ȡ V[index] ��ver ��value ֵ
		int GetVerCost(int index); // ��ȡV[index] ��ver ��cost ֵ
		int GetEdge(int row, int col); // ��ȡedge[row][col] ��ֵ
		void SetVerCost(int index, int cost); private:
};