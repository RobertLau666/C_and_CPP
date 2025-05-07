//Queue.h 
#pragma once 
#include <iostream> 
#include "Stack.h" 
#define MaxSize 30 /*#ifndef MY_DEBUG #define MY_DEBUG #endif/*/ 
class SeqQueue
{
public: SeqQueue(); ~SeqQueue();
		void QueueInitiate(); int QueueNotEmpty(); int QueueAppend(int x); int QueueDelete(int *d); int QueueOrderAppend(int x, Graph &G);
		//A* À„∑® π”√
		int Queue_A_OrderAppend(int x, Graph &G);
private: int queue[MaxSize]; int rear; int front;
		 int count;
};
typedef SeqQueue SeqCQuene;