//Stack.h 
#pragma once 
#include "Graph.h" 
#include <iostream> 
using namespace std; /*#ifndef MY_DEBUG #define MY_DEBUG #endif*/ 
class Stack { public : Stack(); ~Stack(); bool StackNotFull(); bool StakNotEmpty(); void StackPop( Graph &G); void StackPush( int x, Graph &G); void PrintStack( Graph &G); int GetWeight(); private : int a[100]; int top1; int weight; }; 
