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
	cout << endl << "---------- 宽度优先算法 -----------" << endl;
	Graph graphForBFS; graphForBFS.ReadVertex(); graphForBFS.ReadEdge(); 
	Romania_Trip trip; time1 = clock(); 
	trip.BroadFirstSearch(graphForBFS, 0); time2 = clock();
	cout << "--- 耗时： " << time2 - time1 << " ms" << endl;
	cout << endl << "---------- 深度优先算法 ---------" << endl;
	trip.ReSet(); 
	Stack stack;
	Graph graphForDFS; // 要重新取得原始的始地图数据，
	graphForDFS.ReadVertex(); graphForDFS.ReadEdge(); time1 = clock(); trip.DepthFirstSearch(graphForDFS, 0, stack); time2 = clock();
	cout << "--- 耗时： " << time2 - time1 << " ms" << endl;
	cout << endl << "---------- 贪婪算法 ---------------" << endl;
	trip.ReSet();
	Graph graphForGreedy; // 要重新取得原始的始地图数据，
	graphForGreedy.ReadVertex(); graphForGreedy.ReadEdge(); time1 = clock(); trip.Greedy_Algorithms(graphForGreedy, 0); trip.Print(graphForGreedy, trip.GetB(), trip.GetEnd(), 0); time2 = clock();
	cout << "--- 耗时： " << time2 - time1 << " ms" << endl;
	cout << endl << "-------" << "A星算法 ---------" << endl;
	trip.ReSet();
	Graph graphForAStar; // 要重新取得原始的始地图数据，
	graphForAStar.ReadVertex(); graphForAStar.ReadEdge();
	time1 = clock(); trip.AStar_Algorithms(graphForAStar, 0); time2 = clock();
	cout << "--- 耗时： " << time2 - time1 << " ms" << endl;//cout << endl;
	return 0;
}