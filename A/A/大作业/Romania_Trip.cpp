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
	cout << "--- ����·��Ϊ�� ";
	for (size_t i = CityName.size() - 1; i >0; i--) { cout << CityName[i] << "->"; } cout << "Bucharest" << endl;
	cout << "--- ·������Ϊ�� " << Bway << endl << "--- ���ʽڵ���Ϊ�� " << count
		<< endl;
}
// ��������㷨
void Romania_Trip::BroadFirstSearch(Graph & graph, int v) {
	int u, w; i = 0; SeqCQuene queue; visited[v] = 1; count++; if (v == end) return; queue.QueueAppend(v);
	while (queue.QueueNotEmpty()) // ���зǿ�
	{
		queue.QueueDelete(&u); // ȡ���нڵ�
		w = graph.GetFirstVertex(u);
		while (w != -1)    // ���ӽڵ�Ļ�
		{
			if (!visited[w]) {
				Visit(w, u); visited[w] = 1; count++; if (w == end) { Print(graph, b, end, v); return; }
				queue.QueueAppend(w); // �ڵ�ѹ�����
			} w = graph.GetNextVertex(u, w);
		}
	}
}
// ��������㷨
bool isOK = false; int level = 0;
const int Level = 8; // Ԥ����������
void Romania_Trip::DepthFirstSearch(Graph & graph, int v, Stack & stack) {
	int w; i = 0; if (isOK == true) return;
	if (level + 1 > Level) return; // �����������ʱ��������
	level++;
	visited[v] = 1; // ���ʸýڵ�
	count++; stack.StackPush(v, graph); if (v == end || stack.GetWeight() >= MaxWeight) {
		w = -1; if (v == end&& stack.GetWeight() <= MaxWeight) {
			cout << "--- ������ȱ���·��Ϊ�� ";
			stack.PrintStack(graph); /*if (MaxWeight>stack.GetWeight()) MaxWeight = stack.GetWeight();*/
			cout << "--- ·������Ϊ�� " << stack.GetWeight() << endl
				<< "--- ���ʽڵ���Ϊ�� " << count << endl
				<< "--- ������Σ� " << level << endl;
			isOK = true;
		}
	}
	else {
		w = graph.GetFirstVertex(v); // ȡ��ǰ�ڵ�ĵ�һ���ӽڵ�
	} while (w != -1) {
		if (!visited[w])
			DepthFirstSearch(graph, w, stack); // �ݹ����
		w = graph.GetNextVertex(v, w); // ȡ��ǰ�ڵ����һ���ӽڵ�
	}
	visited[v] = 0; // ����ʱ�øýڵ�Ϊδ����
	stack.StackPop(graph); // ���ýڵ㵯��ջ�������� graph ��weight ��ֵ���ĵ�ǰջֵ
		level--;
}
// ̰���㷨
void Romania_Trip::Greedy_Algorithms(Graph & graph, int v)
{
	int u, w;
	SeqCQuene queue; // ���д洢ͼ�ڵ���ͼ�е�����ֵ , ���ȶ��У� value С���ڶ�ͷ
	visited[v] = 1; if (v == end) { return; }
	queue.QueueOrderAppend(v, graph); // ͼ�ڵ㰴����˳�������
	count++;     // ���ʽڵ��� +1
	while (queue.QueueNotEmpty()) // ������ȣ�ѭ��
	{
		queue.QueueDelete(&u); // ɾ������ͷԪ�ز�����ɾ������ֵ
							   //cout << "u= " << u << " ";
		w = graph.GetFirstVertex(u); while (w != -1) {
			if (!visited[w]) {
				Visit(w, u); // ���� w�ڵ㣬�� way b ��ָ�����
				if (w == end) {  //cout << "w==end"; count++;  return ;  } 
					queue.QueueOrderAppend(w, graph); // ͼ�ڵ㰴����˳�������
					count++;
				} w = graph.GetNextVertex(u, w);
			}
		}
	}
}
	//A* �㷨
	void Romania_Trip::AStar_Algorithms(Graph & graph, int v) 
	{ i = 0; 
	count = 0; 
	int u, w;
	SeqCQuene queue; 
		if (v == end) return; // �����յ�
		queue.Queue_A_OrderAppend(v, graph);  count++; while (queue.QueueNotEmpty()) {
			queue.QueueDelete(&u); if (u == end) {
				cout << "--- ·������Ϊ�� " << graph.GetVerCost(u) +
					graph.GetVerValue(u) << endl
					<< "--- ���ʽڵ���Ϊ�� " << count << endl;
				return;
			} w = graph.GetFirstVertex(u); while (w != -1) {
				int cost = graph.GetVerCost(u) + graph.GetEdge(w, u);
				graph.SetVerCost(w, cost); // ���õ�ǰ�ڵ��ƶ���Ŀ��ڵ��Ԥ������
				queue.Queue_A_OrderAppend(w, graph); // ��Ԥ���������������
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
