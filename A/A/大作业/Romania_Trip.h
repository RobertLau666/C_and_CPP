//Romania_Trip.h #pragma once 
#include "Queue.h"
typedef struct { int father; int me; } way;
class Romania_Trip
{
public: Romania_Trip(); ~Romania_Trip();
		void Visit(int v, int u); void Print(Graph &graph, way *b, int end, int start); void BroadFirstSearch(Graph &graph, int v);
		void DepthFirstSearch(Graph &graph, int v, Stack &stack); void Greedy_Algorithms(Graph &graph, int v); void AStar_Algorithms(Graph &graph, int v);
		void ReSet(); int GetCount(); int GetMaxWeight(); int GetEnd(); way* GetB(); private: way *b; int i;
		int end; int count;
		int visitedCity[20]; int MaxWeight; int visited[20];
};