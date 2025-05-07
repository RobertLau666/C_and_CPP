//Graph.h 
#pragma once
using namespace std; 
#define MaxV 20  /*#ifndef MY_DEBUG #define MY_DEBUG #endif*/ 
typedef struct {
char cityname[20]; // 城市名
int  value; // 权值
int  cost; //A* 算法中从当前节点移动到目标节点的预估费用
} Ver;
class Graph {
public: Graph(); ~Graph(); 
		Ver V[MaxV]; 
		int edge[MaxV][MaxV];
		int numofedges;    // 注意这个变量的引用位置
						   // 读取地图节点信息
		void ReadVertex();
		// 读取地图边关系信息
		void ReadEdge();
		// 取与第 V个节点的第一个邻接点
		int GetFirstVertex(int v);
		// 找到第 V1个节点的 V2之后的下一个邻接节点
		int GetNextVertex(int v1, int v2);
		int GetVerValue(int index); // 获取 V[index] 的ver 的value 值
		int GetVerCost(int index); // 获取V[index] 的ver 的cost 值
		int GetEdge(int row, int col); // 获取edge[row][col] 的值
		void SetVerCost(int index, int cost); private:
};