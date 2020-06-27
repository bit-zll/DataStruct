#pragma once

typedef int QDataType;

//队列底层使用链表中节点的结构
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size; //记录队列中有效元素的个数
}Queue;

typedef struct MyStack{
	Queue q1;
	Queue q2;
}MyStack;