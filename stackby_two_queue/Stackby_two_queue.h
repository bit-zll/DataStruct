#pragma once

typedef int QDataType;

//���еײ�ʹ�������нڵ�Ľṹ
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int _size; //��¼��������ЧԪ�صĸ���
}Queue;

typedef struct MyStack{
	Queue q1;
	Queue q2;
}MyStack;