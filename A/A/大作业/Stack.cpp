//Stack.cpp 
#include "Stack.h" 
#include <iostream> 
using namespace std; 
Stack::Stack() { top1 = 0; weight = 0; }
Stack ::~Stack() { } bool Stack::StackNotFull() { if (top1<100) return true; else return false; } bool Stack::StakNotEmpty() { if (top1>0) return true; else return false; }
void Stack::StackPop(Graph & G) {
	int x; if (StakNotEmpty()) {
		top1--; x = a[top1]; if (top1>0)
			weight -= G.edge[a[top1 - 1]][x]; // 弹出节点是 weight 的值要减少相应的数值
	}
	else
		cout << " 栈已空！ " << endl;
}
// 将x入栈
void Stack::StackPush(int x, Graph & G) {
	if (StackNotFull()) { a[top1] = x; if (top1>0) weight = weight + G.edge[a[top1 - 1]][a[top1]]; top1++; }
	else
		cout << " 栈已满！ " << endl;
}
void Stack::PrintStack(Graph & G) 
{
	int x = 0, nWeight = 0; while (x<top1) { cout << G.V[a[x]].cityname; if (x < top1 - 1)cout << "->"; nWeight += weight; x++; }
#ifdef MY_DEBUG 
	cout << endl << "路径长度为： " << nWeight << endl;
#endif cout << endl; 
} 
int Stack::GetWeight()
{
	return weight;
}
