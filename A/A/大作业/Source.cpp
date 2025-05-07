//Source.cpp /*On holiday in Romania; currently in Arad Flight leaves tomorrow from Bucharest
//Formulate goal ; Be in Bucharest
//Formulate problem States : various cities Actions : drive between cities Find solution Sequence of cities; e.g.Arad, Sibiu, Fagaras, Bucharest, */
#include "Graph.h" 
#include "Queue.h"
#include "Stack.h" 
#include "Romania_Trip.h" 
#include <iostream> 
#include <ctime> 
using namespace std; 
int main() {
	long int time1, time2;
	cout << endl << "---------- ��������㷨 -----------" << endl;
	Graph graphForBFS; graphForBFS.ReadVertex(); graphForBFS.ReadEdge(); 
	Romania_Trip trip; time1 = clock(); 
	trip.BroadFirstSearch(graphForBFS, 0); time2 = clock();
	cout << "--- ��ʱ�� " << time2 - time1 << " ms" << endl;
	cout << endl << "---------- ��������㷨 ---------" << endl;
	trip.ReSet(); 
	Stack stack;
	Graph graphForDFS; // Ҫ����ȡ��ԭʼ��ʼ��ͼ���ݣ�
	graphForDFS.ReadVertex(); graphForDFS.ReadEdge(); time1 = clock(); trip.DepthFirstSearch(graphForDFS, 0, stack); time2 = clock();
	cout << "--- ��ʱ�� " << time2 - time1 << " ms" << endl;
	cout << endl << "---------- ̰���㷨 ---------------" << endl;
	trip.ReSet();
	Graph graphForGreedy; // Ҫ����ȡ��ԭʼ��ʼ��ͼ���ݣ�
	graphForGreedy.ReadVertex(); graphForGreedy.ReadEdge(); time1 = clock(); trip.Greedy_Algorithms(graphForGreedy, 0); trip.Print(graphForGreedy, trip.GetB(), trip.GetEnd(), 0); time2 = clock();
	cout << "--- ��ʱ�� " << time2 - time1 << " ms" << endl;
	cout << endl << "-------" << "A���㷨 ---------" << endl;
	trip.ReSet();
	Graph graphForAStar; // Ҫ����ȡ��ԭʼ��ʼ��ͼ���ݣ�
	graphForAStar.ReadVertex(); graphForAStar.ReadEdge();
	time1 = clock(); trip.AStar_Algorithms(graphForAStar, 0); time2 = clock();
	cout << "--- ��ʱ�� " << time2 - time1 << " ms" << endl;//cout << endl;
	return 0;
}