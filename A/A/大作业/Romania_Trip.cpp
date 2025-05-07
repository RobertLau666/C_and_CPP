// Romania_Trip.cpp 
#include "Romania_Trip.h" 
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;
Romania_Trip::Romania_Trip()
{
	b = new way[100]; i = 0; end = 2; count = 0; MaxWeight = 10000; for (size_t i = 0; i < 20; i++) { visited[i] = 0; }
}
void Romania_Trip::ReSet() {
	if (NULL != b) delete[]b; b = new way[20]; i = 0;
	end = 2; count = 0; for (size_t i = 0; i < 20; i++) { visited[i] = 0; }
} Romania_Trip ::~Romania_Trip() { if (NULL != b) delete[]b; }
void Romania_Trip::Visit(int v, int u) {
	b[i].father = u; b[i].me = v; i++;
} void Romania_Trip::Print(Graph & graph, way * b, int end, int start) {
	int Bway = 0; vector <string > CityName; string name = graph.V[end].cityname; CityName.push_back(name);
	while (1) { for (int j = 0; j<i; j++) { if (b[j].me == end) { name = graph.V[b[j].father].cityname; CityName.push_back(name); Bway += graph.edge[b[j].me][b[j].father]; end = b[j].father; } } if (end == start) break; }
	cout << "--- 遍历路径为： ";
	for (size_t i = CityName.size() - 1; i >0; i--) { cout << CityName[i] << "->"; } cout << "Bucharest" << endl;
	cout << "--- 路径长度为： " << Bway << endl << "--- 访问节点数为： " << count
		<< endl;
}
// 宽度优先算法
void Romania_Trip::BroadFirstSearch(Graph & graph, int v) {
	int u, w; i = 0; SeqCQuene queue; visited[v] = 1; count++; if (v == end) return; queue.QueueAppend(v);
	while (queue.QueueNotEmpty()) // 队列非空
	{
		queue.QueueDelete(&u); // 取队列节点
		w = graph.GetFirstVertex(u);
		while (w != -1)    // 有子节点的话
		{
			if (!visited[w]) {
				Visit(w, u); visited[w] = 1; count++; if (w == end) { Print(graph, b, end, v); return; }
				queue.QueueAppend(w); // 节点压入队列
			} w = graph.GetNextVertex(u, w);
		}
	}
}
// 深度优先算法
bool isOK = false; int level = 0;
const int Level = 8; // 预设的搜索层次
void Romania_Trip::DepthFirstSearch(Graph & graph, int v, Stack & stack) {
	int w; i = 0; if (isOK == true) return;
	if (level + 1 > Level) return; // 大于搜索层次时不再深入
	level++;
	visited[v] = 1; // 访问该节点
	count++; stack.StackPush(v, graph); if (v == end || stack.GetWeight() >= MaxWeight) {
		w = -1; if (v == end&& stack.GetWeight() <= MaxWeight) {
			cout << "--- 深度优先遍历路径为： ";
			stack.PrintStack(graph); /*if (MaxWeight>stack.GetWeight()) MaxWeight = stack.GetWeight();*/
			cout << "--- 路径长度为： " << stack.GetWeight() << endl
				<< "--- 访问节点数为： " << count << endl
				<< "--- 搜索层次： " << level << endl;
			isOK = true;
		}
	}
	else {
		w = graph.GetFirstVertex(v); // 取当前节点的第一个子节点
	} while (w != -1) {
		if (!visited[w])
			DepthFirstSearch(graph, w, stack); // 递归访问
		w = graph.GetNextVertex(v, w); // 取当前节点的下一个子节点
	}
	visited[v] = 0; // 返回时置该节点为未访问
	stack.StackPop(graph); // 将该节点弹出栈，并根据 graph 中weight 的值更改当前栈值
		level--;
}
// 贪婪算法
void Romania_Trip::Greedy_Algorithms(Graph & graph, int v)
{
	int u, w;
	SeqCQuene queue; // 队列存储图节点在图中的索引值 , 优先队列， value 小的在队头
	visited[v] = 1; if (v == end) { return; }
	queue.QueueOrderAppend(v, graph); // 图节点按优先顺序入队列
	count++;     // 访问节点数 +1
	while (queue.QueueNotEmpty()) // 宽度优先，循环
	{
		queue.QueueDelete(&u); // 删除队列头元素并返回删除的数值
							   //cout << "u= " << u << " ";
		w = graph.GetFirstVertex(u); while (w != -1) {
			if (!visited[w]) {
				Visit(w, u); // 访问 w节点，将 way b 的指向更新
				if (w == end) {  //cout << "w==end"; count++;  return ;  } 
					queue.QueueOrderAppend(w, graph); // 图节点按优先顺序入队列
					count++;
				} w = graph.GetNextVertex(u, w);
			}
		}
	}
}
	//A* 算法
	void Romania_Trip::AStar_Algorithms(Graph & graph, int v) 
	{ i = 0; 
	count = 0; 
	int u, w;
	SeqCQuene queue; 
		if (v == end) return; // 到达终点
		queue.Queue_A_OrderAppend(v, graph);  count++; while (queue.QueueNotEmpty()) {
			queue.QueueDelete(&u); if (u == end) {
				cout << "--- 路径长度为： " << graph.GetVerCost(u) +
					graph.GetVerValue(u) << endl
					<< "--- 访问节点数为： " << count << endl;
				return;
			} w = graph.GetFirstVertex(u); while (w != -1) {
				int cost = graph.GetVerCost(u) + graph.GetEdge(w, u);
				graph.SetVerCost(w, cost); // 设置当前节点移动到目标节点的预估费用
				queue.Queue_A_OrderAppend(w, graph); // 按预估费用优先入队列
				count++; w = graph.GetNextVertex(u, w);
			}
		}
	}
	int Romania_Trip::GetCount()
	{ return count; } 
	int Romania_Trip::GetMaxWeight() 
	{ return MaxWeight; } 
	int Romania_Trip::GetEnd() 
	{ return end; } 
	way * Romania_Trip::GetB()
	{ return b; }
