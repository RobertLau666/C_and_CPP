//Queue.cpp
#include "Queue.h" 
#include <iostream> 
#include "Stack.h"
SeqQueue::SeqQueue() { rear = 0; front = 0; count = 0; }
SeqQueue::~SeqQueue() { }
int SeqQueue::QueueNotEmpty() { if (count != 0) return 1; else return 0; } int SeqQueue::QueueAppend(int x) {
	if (count>0 && rear == front) {
		cout << " 队列已满 " << endl;
		return 0;
	}
	else {
		queue[rear] = x; rear = (rear + 1) % MaxSize; count++; return 1;
	}
} int SeqQueue::QueueDelete(int * d) {
	if (count == 0) {
		cout << " 队列已空 " << endl;
		return 0;
	}
	else {
		*d = queue[front]; front = (front + 1) % MaxSize; count--; return 1;
	}
}
void SeqQueue::QueueInitiate()
{
}
int SeqQueue::QueueOrderAppend(int x, Graph & G) {
	if (count>0 && rear == front) {
		cout << " 队列已满 " << endl;
		return 0;
	}
	else {
		if (count == 0 || G.V[x].value >= G.V[queue[rear - 1]].value) // 队尾插入
		{
			queue[rear] = x; rear = (rear + 1) % MaxSize; count++; return 1;
		}
		else {
			if (G.V[x].value <= G.V[queue[front]].value) // 队头插入
			{
				queue[front - 1] = x; front = (front - 1 + MaxSize) % MaxSize; count++; return 1;
			}
			else // 排序找位置插入
			{
				int position = front; while (G.V[x].value> G.V[queue[position]].value) { position++; } int i; for (i = front; i<position; i++) { queue[(i - 1 + MaxSize) % MaxSize] = queue[i% MaxSize]; } queue[(i - 1 + MaxSize) % MaxSize] = x; front = (front - 1 + MaxSize) % MaxSize; count++; return 1;
			}
		}
	}
	return 0;
}
//A* 
int SeqQueue::Queue_A_OrderAppend(int x, Graph & G) {
	if (count > 0 && rear == front) {
		cout << " 队列已满 " << endl;
		return 0;
	}
	else {
		int x1 = G.V[x].value + G.V[x].cost;
		int x2 = 0; if (count != 0) x2 = G.V[queue[rear - 1]].value + G.V[queue[rear - 1]].cost;
		if (count == 0 || x1 > x2) // 队尾插入
		{
			queue[rear] = x; rear = (rear + 1) % MaxSize; count++; return 1;
		}
		else
		{         // 队头插入
			if (G.V[x].value + G.V[x].cost < G.V[queue[front]].value + G.V[queue[front]].cost) { queue[front - 1] = x; front = (front - 1 + MaxSize) % MaxSize; count++; return 1; }
			else // 排序找位置插入
			{
				int position = front; while (G.V[x].value + G.V[x].cost > G.V[queue[position% MaxSize]].value + G.V[queue[position% MaxSize]].cost) { position++; } int i;
				for (i = front; i < position; i++) { queue[(i - 1 + MaxSize) % MaxSize] = queue[i% MaxSize]; } queue[(i - 1 + MaxSize) % MaxSize] = x; front = (front - 1 + MaxSize) % MaxSize; count++;
				return 1;
			}
		}
	} return 0;
}