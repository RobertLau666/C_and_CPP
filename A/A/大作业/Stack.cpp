//Stack.cpp 
#include "Stack.h" 
#include <iostream> 
using namespace std; 
Stack::Stack() { top1 = 0; weight = 0; }
Stack ::~Stack() { } bool Stack::StackNotFull() { if (top1<100) return true; else return false; } bool Stack::StakNotEmpty() { if (top1>0) return true; else return false; }
void Stack::StackPop(Graph & G) {
	int x; if (StakNotEmpty()) {
		top1--; x = a[top1]; if (top1>0)
			weight -= G.edge[a[top1 - 1]][x]; // �����ڵ��� weight ��ֵҪ������Ӧ����ֵ
	}
	else
		cout << " ջ�ѿգ� " << endl;
}
// ��x��ջ
void Stack::StackPush(int x, Graph & G) {
	if (StackNotFull()) { a[top1] = x; if (top1>0) weight = weight + G.edge[a[top1 - 1]][a[top1]]; top1++; }
	else
		cout << " ջ������ " << endl;
}
void Stack::PrintStack(Graph & G) 
{
	int x = 0, nWeight = 0; while (x<top1) { cout << G.V[a[x]].cityname; if (x < top1 - 1)cout << "->"; nWeight += weight; x++; }
#ifdef MY_DEBUG 
	cout << endl << "·������Ϊ�� " << nWeight << endl;
#endif cout << endl; 
} 
int Stack::GetWeight()
{
	return weight;
}
